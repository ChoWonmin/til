// Test.cpp : Defines the entry point for the console application.
//

#include "GLUK/Viewers/viewer.hpp"
#include "GLUK/Objects/object.hpp"
#include "GLUK/Assets/material.hpp"
#include "GLUK/Assets/assetLib.hpp"
#include "GLUK/Assets/fbo.hpp"
#include "GLUK/nanovg/nanoUI.hpp"
#ifdef _MSC_VER
#ifdef _DEBUG
#pragma comment(lib, "glukd")
#else
#pragma comment(lib, "gluk")
#endif
#endif

int pin1 = 1;
int pin2 = 1;

float airDrag = 0.08; // 공기저항력
float G = 981;        // 중력가속도
float mu = 0.2;       // 마찰계수
float alpha = 0.05;   // 반발계수
const float defaultMass = 0.01;
const float defaultKs = 50; // 탄성계수
const float defaultKd = 0.3;

const int timeStep = 10;
vec3 startPoint = vec3(-50, 100, 0);
Sphere hurdle;
vec3 hurdleCenter = vec3(0, 35, -50);
float hurdleRadius = 30;

struct Particle
{
  vec3 f;
  float m;
  vec3 v;
  vec3 x;

  Particle(const vec3 &x0, const vec3 &v0 = vec3(0), float mass = defaultMass)
      : x(x0), m(mass), f(0), v(v0) {}

  void clearForce()
  {
    f = vec3(0);
  }

  void addForce(const vec3 &force)
  {
    f += force;
  }

  void eval(float dt)
  {
    v += f / m * dt;
    x += v * dt;
  }
};

struct Spring
{
  float ks = defaultKs;
  float kd = defaultKd;
  int i, j;
  float r;
  float val;

  Spring(int i0, int j0, float intensity, const std::vector<Particle> &particles)
      : i(i0), j(j0), val(intensity)
  {
    r = length(particles[i].x - particles[j].x);
  }

  void applyForce(std::vector<Particle> &particles)
  {
    vec3 dx = particles[i].x - particles[j].x;
    vec3 dv = particles[i].v - particles[j].v;
    float lx = length(dx);

    vec3 f = -(ks * (lx - r) + kd * dot(dv, dx) / lx) * dx / lx;
    f = val * f;

    particles[i].addForce(f);
    particles[j].addForce(-f);
  }
};

std::vector<Particle> particles;
std::vector<Spring> springs;

void render(PASS_TYPE pass, const Camera &camera);
void initialize();
void frame(float deltaT);
void renderGUI(NVGcontext *vg, const ivec2 &size);
int eventCallback(Viewer3D::EVENT_TYPE event, int d1, int d2, int d3);

AnimViewer viewer;
nanoGroup gui(0, 40, 0, 0, "");

int eventCallback(Viewer3D::EVENT_TYPE event, int mods, int dt2, int dt3)
{

  if (event == Viewer3D::EVENT_KEY_DOWN)
  {
    if (dt2 == '1')
    {
      pin1 = 0;
    }

    if (dt2 == '2')
    {
      pin2 = 0;
    }
  }

  return 0;
}

int main(void)
{
  viewer.create(1200, 600, "Title");
  viewer.setInitCallback(initialize);
  viewer.setFrameCallback(frame);
  viewer.setRenderCallback(render);
  viewer.setEventCallback(eventCallback);

  viewer.setKeyTimes({0, 1, 2, 3, 4, 5, 6, 7.5, 10});
  viewer.setAnimationLength(10);
  viewer.run();
}

void initialize()
{
  pin1 = 1;
  pin2 = 1;
  particles.clear();
  springs.clear();

  int width = 12;
  int height = 12;
  int distance = 10;
  vec3 speed = vec3(0, 0, 0);

  hurdle.center = hurdleCenter;
  hurdle.radius = hurdleRadius;
  hurdle.setMaterial(AssetLib::get().registerMaterial("MovingObj", vec4(1, 0, 1, 1)));

  for (int i = 0; i < width; i++)
  {
    for (int j = 0; j < height; j++)
    {
      vec3 point = startPoint;
      point.x += distance * i;
      point.z -= distance * j;

      particles.push_back(Particle(point, speed));
    }
  }

  int current = 0;
  for (int i = 0; i < width; i++)
  {
    for (int j = 0; j < height; j++)
    {

      if (j != height - 1)
      { // up
        springs.push_back(Spring(current, current + 1, 1.0, particles));
      }

      if (i != width - 1)
      { // right
        springs.push_back(Spring(current, current + height, 1.0, particles));
      }

      if (i != width - 1 && j != height - 1)
      { // right-up
        springs.push_back(Spring(current, current + height + 1, 0.7, particles));
      }

      if (i != width - 1 && j != 0)
      { // right-down
        springs.push_back(Spring(current, current + height - 1, 0.7, particles));
      }
      //
      //            // banding spring
      //
      //            if (j < height-2) { // 2 order up
      //                springs.push_back(Spring(current, current+2, 0.3, particles));
      //            }
      //
      //            if (i < width-2) { // 2 order up
      //                springs.push_back(Spring(current, current+2*height, 0.3, particles));
      //            }

      current++;
    }
  }
}

void render(PASS_TYPE pass, const Camera &cam)
{
  for (auto &s : springs)
  {
    Cylinder::render(1, particles[s.i].x, particles[s.j].x);
  }

  for (auto &p : particles)
  {
    Cube::render(vec3(4), p.x);
  }

  AssetLib::get().render(&hurdle);
}

void frame(float dt)
{
  if (dt < 0.0001)
  {
    initialize();
    return;
  }

  int count = 0;

  while (count < timeStep)
  {
    count++;

    for (auto &p : particles)
    {
      p.clearForce();
    }

    for (auto &p : particles)
    {
      p.addForce(p.m * G * vec3(0, -1, 0));
      p.addForce(-airDrag * p.v);
    }

    for (auto &s : springs)
    {
      s.applyForce(particles);
    }

    for (auto &particle : particles)
    { // hurdle
      vec3 N = normalize(particle.x - hurdle.center);
      vec3 wall = hurdle.center + N * hurdle.radius;
      float eps = 0.1;

      if (dot(particle.x - wall, N) < eps)
      {

        if (abs(dot(particle.v, N)) < 10)
        { // contact

          float FN = -dot(particle.f, N); // 수직항력

          if (FN > 0)
          {
            vec3 frictionalForce = -normalize(particle.v) * FN * mu; // 마찰력
            particle.f += frictionalForce;
          }

          vec3 vN = dot(particle.v, N) * N;
          vec3 vT = particle.v - vN;

          particle.v = vT;
          particle.x.y = max(wall.y, particle.x.y);
        }
        else if (dot(particle.v, N) < 0)
        { // collision
          vec3 vN = dot(particle.v, N) * N;
          vec3 vT = particle.v - vN;

          particle.v = vT - alpha * vN;
          particle.x = max(wall, particle.x);
        }
      }
    }

    for (auto &particle : particles)
    {                            // floor
      vec3 wall = vec3(0, 3, 0); // wall
      vec3 N = vec3(0, 1, 0);

      float eps = 0.1;

      if (dot(particle.x - wall, N) < eps)
      {

        if (abs(dot(particle.v, N)) < 10)
        { // contact

          float FN = -dot(particle.f, N); // 수직항력

          if (FN > 0)
          {
            vec3 frictionalForce = -normalize(particle.v) * FN * mu; // 마찰력
            particle.f += frictionalForce;
          }

          vec3 vN = dot(particle.v, N) * N;
          vec3 vT = particle.v - vN;

          particle.v = vT;
          particle.x.y = max(wall.y, particle.x.y);
        }
        else if (dot(particle.v, N) < 0)
        { // collision
          vec3 vN = dot(particle.v, N) * N;
          vec3 vT = particle.v - vN;

          particle.v = vT - alpha * vN;
          particle.x.y = max(wall.y, particle.x.y);
        }
      }
    }

    for (auto &p : particles)
    {
      p.eval(dt / timeStep);
    }

    if (pin1)
    {
      particles[0].x = startPoint;
      particles[0].v = vec3(0);
    }

    if (pin2)
    {
      particles[11].x = vec3(-50, 100 - 110);
      particles[11].v = vec3(0);
    }
  }
}
