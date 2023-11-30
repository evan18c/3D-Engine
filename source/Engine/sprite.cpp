// Includes
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "Engine/utils.h"

// Header
#include <Engine/sprite.h>

Sprite::Sprite(const char *bmpFile) {

    // Default Config
    posX = 0;
    posY = 0;

    // Reading bmp file
    int dimensions[2];
    char *data = readBMP(bmpFile, (int *)&dimensions);
    width = dimensions[0];
    height = dimensions[1];
    
    // Loading texture
    texture = 0;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    
}

uint32_t Sprite::getWidth() {
    return width;
}

uint32_t Sprite::getHeight() {
    return height;
}

uint32_t Sprite::getTexture() {
    return texture;
}