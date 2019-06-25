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

float airDrag = 0.03;

struct Particle
{
  vec3 f;
  float m;
  vec3 v;
  vec3 x;

  Particle(const vec3 &x0, const vec3 &v0 = vec3(0), float mass = 0.05)
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
  float ks = 100;
  float kd = 0.3;
  int i, j;
  float r;

  Spring(int i0, int j0, const std::vector<Particle> &particles)
      : i(i0), j(j0)
  {
    r = length(particles[i].x - particles[j].x);
  }

  void applyForce(std::vector<Particle> &particles)
  {
    vec3 dx = particles[i].x - particles[j].x;
    vec3 dv = particles[i].v - particles[j].v;
    float lx = length(dx);

    vec3 f = -(ks * (lx - r) + kd * dot(dv, dx) / lx) * dx / lx;

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

const int width = 80, height = 60;
int winW, winH;
AnimViewer viewer;
nanoGroup gui(0, 40, 0, 0, "");

Fbo fbo;
GLuint keyframeMat = 0, selectedMat = 0, pointsMat = 0;

int eventCallback(Viewer3D::EVENT_TYPE event, int mods, int dt2, int dt3)
{
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
  particles.clear();
  springs.clear();

  particles.push_back(Particle(vec3(0, 100, 0), vec3(0, 0, 0)));
  particles.push_back(Particle(vec3(20, 100, 0), vec3(0, 0, 0)));
  particles.push_back(Particle(vec3(40, 100, 0), vec3(0, 0, 0)));
  particles.push_back(Particle(vec3(60, 100, 0), vec3(0, 0, 0)));

  springs.push_back(Spring(0, 1, particles));
  springs.push_back(Spring(1, 2, particles));
  springs.push_back(Spring(2, 3, particles));
}

void render(PASS_TYPE pass, const Camera &cam)
{
  for (auto &s : springs)
  {
    Cylinder::render(3, particles[s.i].x, particles[s.j].x);
  }

  for (auto &p : particles)
  {
    Sphere::render(5, p.x);
  }
}

void frame(float dt)
{
  if (dt < 0.0001)
  {
    initialize();
    return;
  }

  for (auto &p : particles)
  {
    p.clearForce();
  }

  for (auto &p : particles)
  {
    p.addForce(p.m * 981 * vec3(0, -1, 0));
    p.addForce(-airDrag * p.v);
  }

  for (auto &s : springs)
  {
    s.applyForce(particles);
  }

  for (auto &p : particles)
  {
    p.eval(dt);
  }

  for (auto &particle : particles)
  {
    vec3 p = vec3(0, 5, 0); // wall
    vec3 N = vec3(0, 1, 0);

    float eps = 0.1;

    if (dot(particle.x - p, N) < eps && dot(particle.v, N) < 0)
    {
      vec3 vN = dot(particle.v, N) * N;
      vec3 vT = particle.v - vN;

      particle.v = vT - 0.5f * vN; // 반발계수
      particle.x.y = max(5.f, particle.x.y);
    }
  }
}
