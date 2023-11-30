#version 330 core

// INPUTS
in vec2 UV;

// UNIFORM
uniform sampler2D texture2d;

// OUTPUT
out vec4 _output;

// Variables
vec4 pixel;

// MAIN
void main()
{
    pixel = texture(texture2d, UV);

    // Check for transparency (0,0,0) pixel
    if (pixel.r + pixel.g + pixel.b == 3) {
        _output = vec4(0, 0, 0, 0);
    } else {
        _output = pixel;
    }
}