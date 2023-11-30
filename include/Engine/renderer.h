#pragma once
// Includes
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Engine/engine.h"

class Renderer {
    public:
        Renderer();
        void update();
        void renderModel(Model model);
        uint32_t getShader();

    private:
        uint32_t shader;
};