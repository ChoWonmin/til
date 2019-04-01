//
//  main.cpp
//  Cartoon
//
//  Created by Wonmin Cho on 01/04/2019.
//  Copyright © 2019 Wonmin Cho. All rights reserved.
//
#include <stdlib.h>
#include <GLFW/glfw3.h>

float color = 0.f;

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
    GLFWwindow* window = glfwCreateWindow( 640, 480, "Hello", NULL, NULL );
    glfwMakeContextCurrent( window );
    
    init();
    
    while ( !glfwWindowShouldClose( window ) ) {
        render( window );
        glfwPollEvents();
    }
    glfwDestroyWindow( window );
    glfwTerminate();
}
void render( GLFWwindow* window ) {
    color += 0.001;
    if (color > 1.f)
        color = 0.f;
    
    int width, height;
    glfwGetFramebufferSize( window, &width, &height );
    glViewport( 0, 0, width, height );
    glClearColor( 0, 0, color, 0 );
    glClear( GL_COLOR_BUFFER_BIT );
    glfwSwapBuffers( window );
}
void init() {
    
}
