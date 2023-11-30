#pragma once
// Includes
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

// Sprites support Positioning, Rotation, Texturing.
class Sprite {

    public:
        Sprite(const char *bmpFile);
        uint32_t getWidth();
        uint32_t getHeight();
        uint32_t getTexture();
        uint32_t posX, posY; // Defines bottom left coords

    private:
        uint32_t width, height;
        uint32_t texture;

};