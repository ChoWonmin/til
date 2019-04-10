#version 410 core
out vec4 FragColor;

in vec3 normal;
in vec3 worldPos;

uniform vec3 lightPos = vec3(3,5,3);
uniform vec3 cameraPosition = vec3(0,0,5);

void main()
{
    vec3 N = normalize(normal);
    vec3 L = normalize(lightPos - worldPos);
    vec3 V = normalize(worldPos - cameraPosition);
    vec3 R = N*dot(N,L)*2-L;
    
    vec3 color =  dot(N,L) * vec3(.9,.4,0);
    color += vec3(1,.5,0) * pow(clamp(dot(R,V),0,1),500);
    
    FragColor = vec4(color, 1);
    
}
