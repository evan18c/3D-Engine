#pragma once
// Includes
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class Text {

    public:
        Text(const char *text, uint32_t x, uint32_t y);
        uint32_t getVao();
        uint32_t getTexture();
        uint32_t posX;
        uint32_t posY;


    private:
        uint32_t vao;
        uint32_t texture;

};