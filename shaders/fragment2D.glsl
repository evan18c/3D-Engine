#version 330 core

// INPUTS
in vec2 UV;

// UNIFORM
uniform sampler2D texture2d;

// OUTPUT
out vec4 _output;

// MAIN
void main()
{
    _output = texture(texture2d, UV);
}