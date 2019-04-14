//
//  main.cpp
//  Cartoon
//
//  Created by Wonmin Cho on 01/04/2019.
//  Copyright © 2019 Wonmin Cho. All rights reserved.
//

#define GLM_ENABLE_EXPERIMENTAL
#define PI 3.14159265358979f

#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>
#include "shader_s.h"
#include "loadObj.hpp"

#ifdef __APPLE__
#include <OpenGL/gl3ext.h>
#endif

#include <iostream>
#include <vector>

using namespace std;

float camPitch = 0.0;
float camYaw = 180.0;
float camFov = 40;

double lastX = 0.0;
double lastY = 0.0;

std::vector< glm::vec3 > vertices;
std::vector< glm::vec2 > uvs;
std::vector< glm::vec3 > normals;
unsigned vertexBuffer, normalBuffer ,VIO, VAO = 0;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void render( GLFWwindow* window );
void init();

void cursorCallback(GLFWwindow* win, double x, double y){
    if(glfwGetMouseButton(win, GLFW_MOUSE_BUTTON_1)){
        int width, height;
        glfwGetWindowSize(win, &width, &height);
        
        camPitch += (y-lastY)/height*180;
        camPitch = (camPitch < 90-0.5)?camPitch:90-0.5;
        camPitch = (camPitch > -90+0.5)?camPitch:-90+0.5;
        
        camYaw += (x-lastX)/width*180;
        
        lastX = x;
        lastY = y;
    }
}
void buttonCallback(GLFWwindow* win, int btn, int action, int mods ) {
    if( btn == GLFW_MOUSE_BUTTON_1 && action == GLFW_PRESS ) {
        glfwGetCursorPos(win, &lastX, &lastY );
    }
}
void scrollCallback(GLFWwindow* win, double dx, double dy){
    camFov += dy/10;
    
    camFov = (camFov<170)?camFov:170;
    camFov = (camFov>10)?camFov:10;
}

int main(void){
    if ( !glfwInit() ) exit(EXIT_FAILURE);
#ifdef __APPLE__
    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 4 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 1 );
    glfwWindowHint (GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
#endif
    GLFWwindow* window = glfwCreateWindow(720, 640, "Hello", NULL, NULL);
    glfwMakeContextCurrent( window );
    
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, cursorCallback);
    glfwSetMouseButtonCallback(window, buttonCallback);
    glfwSetScrollCallback(window, scrollCallback);
    
    Shader shaderProgram("shader.vs", "shader.fs");
    
    bool res = loadOBJ("spot_triangulated.obj", vertices, uvs, normals);
    
    if (res==0) {
        cout << "obg loader error!!!!\n";
    }
    
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    
    glGenBuffers(1, &normalBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
    glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3), &normals[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
    
    while ( !glfwWindowShouldClose( window ) ) {
        int width, height;
        glfwGetFramebufferSize( window, &width, &height );
        glViewport( 0, 0, width, height );
        glClearColor( 1.0, 1.0, 1.0, 0 );
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_DEPTH_TEST);
        
        glm::mat4 projMat = glm::perspective( camFov*PI/180, width/(float)height, 0.1f, 100.f);
        glm::mat4 viewMat = lookAt( glm::vec3(0,0,5),glm::vec3(0,0,0),glm::vec3(0,1,0));
        glm::mat4 modelMat = glm::rotate(camYaw*PI/180, glm::vec3(0,1,0)) * glm::rotate(camPitch*PI/180, glm::vec3(1,0,0)) * glm::mat4(1);

        GLuint loc;
        loc = glGetUniformLocation( shaderProgram.ID, "projMat" );
        glUniformMatrix4fv( loc, 1, false, value_ptr(projMat));
        loc = glGetUniformLocation( shaderProgram.ID, "viewMat" );
        glUniformMatrix4fv( loc, 1, false, value_ptr(viewMat));
        loc = glGetUniformLocation( shaderProgram.ID, "modelMat" );
        glUniformMatrix4fv( loc, 1, false, value_ptr(modelMat));
    
        shaderProgram.use();
        glBindVertexArray(VAO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VIO);
        
        glDrawArrays(GL_TRIANGLES, 0, 3*vertices.size());
        
        glfwSwapBuffers( window );
        glfwPollEvents();
    }
    glfwDestroyWindow( window );
    glfwTerminate();
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

