#version 330 core

// INPUTS
layout (location = 0) in vec3 vertexPosition;
layout (location = 1) in vec2 vertexUV;

// OUTPUTS
out vec2 UV;
out vec3 Normal;

//MAIN
void main()
{
    UV = vertexUV;
    Normal = vertexNormal;

    // Vertex Position
    gl_Position = Projection * View * Model * vec4(vertexPosition, 1);
}