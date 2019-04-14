#version 410 core
out vec4 FragColor;

in vec3 normal;
in vec3 worldPos;

uniform vec3 lightPos = vec3(3,5,3);
uniform vec3 cameraPosition = vec3(0,0,5);

const int levels = 3;
const float scaleFactor = 1.0/levels;

void main()
{
    vec3 N = normalize(normal);
    vec3 L = normalize(lightPos - worldPos);
    
    float nDotL = dot(N,L);
    
    vec3 color = vec3(0.9, 0.9, 0.9) * floor(nDotL * levels) * scaleFactor;
    
    FragColor = vec4(color, 1);
    
}

