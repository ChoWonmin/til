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

std::vector< glm::vec3 > vertices;
std::vector< glm::vec2 > uvs;
std::vector< glm::vec3 > normals;
unsigned vertexBuffer, VIO, VAO = 0;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void render( GLFWwindow* window );
void init();


int main(void){
    if ( !glfwInit() ) exit(EXIT_FAILURE);
#ifdef __APPLE__
    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 4 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 1 );
    glfwWindowHint (GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
#endif
    GLFWwindow* window = glfwCreateWindow(640, 640, "Hello", NULL, NULL);
    glfwMakeContextCurrent( window );
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
    Shader shaderProgram("shader.vs", "shader.fs");
    
    bool res = loadOBJ("spot_triangulated.obj", vertices, uvs, normals);
    
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);
    
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    
    
    while ( !glfwWindowShouldClose( window ) ) {
        int width, height;
        glfwGetFramebufferSize( window, &width, &height );
        glViewport( 0, 0, width, height );
        glClearColor( 1.0, 1.0, 1.0, 0 );
        glClear( GL_COLOR_BUFFER_BIT );
    
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

