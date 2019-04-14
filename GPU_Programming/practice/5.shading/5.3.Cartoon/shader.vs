#version 410 core

layout(location=0) in vec3 in_Position;
layout(location=1) in vec3 in_Normal;

uniform mat4 modelMat;
uniform mat4 viewMat;
uniform mat4 projMat;

out vec3 normal;
out vec3 worldPos;

void main(void)
{
    vec4 world_pos = modelMat * vec4(in_Position, 1.0);
    gl_Position = projMat * viewMat * world_pos;
    
    normal = (modelMat * vec4(in_Normal,0)).xyz;
    worldPos = world_pos.xyz;
    
}
