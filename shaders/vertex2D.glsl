#version 330 core

// INPUTS
layout (location = 0) in vec3 vertexPosition;
layout (location = 1) in vec2 vertexUV;

// UNIFORMS
uniform mat4 Transformation;

// OUTPUTS
out vec2 UV;

// MAIN
void main()
{
    // Pass to fragmente
    UV = vertexUV;

    // Vertex Position
    gl_Position = Transformation * vec4(vertexPosition, 1);
}