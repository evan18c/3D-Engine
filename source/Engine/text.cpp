// Includes
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

// Include header
#include "Engine/text.h"

Text::Text(const char *text, uint32_t x, uint32_t y) {

    // Create Vertices
    std::vector<glm::vec2> top_left;
    std::vector<glm::vec2> top_right;
    std::vector<glm::vec2> bottom_left;
    std::vector<glm::vec2> bottom_right;

    // Filling vertices, character size is fixed at 32x32
    for (int i=0; i<sizeof(text); i++) {
        top_left.push_back(glm::vec2(0 + i*32, 0));
        top_right.push_back(glm::vec2(32 + i*32, 0));
        bottom_left.push_back(glm::vec2(0 + i*32, 32));
        bottom_right.push_back(glm::vec2(32 + i*32, 32));
    }


    // Generate VAO
    vao = 0;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // Generate VBOs for vertices and uvs
    uint32_t vbo1;
    glGenBuffers(1, &vbo1);
    glBindBuffer(GL_ARRAY_BUFFER, vbo1);


    // Generate Texture

}

uint32_t Text::getVao() {
    return 0;
}

uint32_t Text::getTexture() {
    return 0;
}