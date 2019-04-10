#version 410 core
out vec4 FragColor;

in vec3 normal;
in vec3 worldPos;

uniform vec3 lightPos = vec3(3,5,3);
uniform vec3 cameraPosition = vec3(0,0,5);

#define threshold 0.25

void main()
{
    vec3 N = normalize(normal);
    vec3 V = normalize(worldPos - cameraPosition);
    
    float silhouettes = dot(N, V);
    
    if (silhouettes < threshold && silhouettes > -threshold) {
        FragColor = vec4(0.0, 0.0, 0.0, 1.0);
    } else {
        FragColor = vec4(1.0, 1.0, 1.0, 1.0);
    }

}
