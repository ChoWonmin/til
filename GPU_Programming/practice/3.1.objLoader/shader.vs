#version 410 core

layout(location=0) in vec3 in_Position;
uniform mat4 modelMat;
uniform mat4 viewMat;
uniform mat4 projMat;

void main(void)
{
    vec4 worldPos = modelMat * vec4(in_Position, 1.0);
    gl_Position= projMat*viewMat*worldPos;
}


