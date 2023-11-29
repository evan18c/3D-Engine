#version 330 core

// INPUTS
in vec2 UV;
in vec3 Normal;

// UNIFORMS
uniform sampler2D textureSampler; // texture from C++
uniform vec3 lightDirection;

// OUTPUT
out vec3 _output; // Final pixel color

// VARIABLES
float ambientLight = 0.25;
vec3 lightColor = vec3(0.2, 0.1, 0.0);
vec3 textureColor;
float intensity;

// MAIN
void main()
{
    textureColor = texture(textureSampler, UV).rgb;
    intensity = max(dot(Normal, lightDirection), ambientLight);

    _output = (textureColor + lightColor) * intensity;
}