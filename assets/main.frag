#version 330 core

//uniform vec3 backgroundColor;
//uniform vec3 lightDir;
//uniform vec3 lightPos;

in float cameraDist;
in vec3 vColor;
in vec3 vPos;
flat in vec3 vNormal;

out vec4 FragColor;

void main()
{
    vec3 lightDir = normalize(vec3(-1.0, 3.0, 2.0));
    float lightAmount = max(0.2, dot(vNormal, lightDir));
    FragColor = vec4(vColor * lightAmount, 1.0);
}