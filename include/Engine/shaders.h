#pragma once

namespace Shaders {

    const char *vertex = R"(
        #version 330 core

        // INPUTS
        layout (location = 0) in vec3 vertexPosition;
        layout (location = 1) in vec2 vertexUV;
        layout (location = 2) in vec3 vertexNormal;

        // UNIFORMS
        uniform mat4 Model;
        uniform mat4 View;
        uniform mat4 Projection;

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
    )";

    const char *fragment = R"(
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
        vec3 lightColor = vec3(0.0, 0.0, 0.0);
        vec3 textureColor;
        float intensity;

        // MAIN
        void main()
        {
            _output = texture(textureSampler, UV).rgb;
        }
    )";

    const char *vertex2D = R"(
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
    )";

    const char *fragment2D = R"(
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
    )";
}