#pragma once
// Includes
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

// Models support Positioning, Rotation, Texturing.
class Model {
    
    public:
        Model(const char *objFile, const char *bmpFile);
        uint32_t getTriangles();
        uint32_t getVao();
        uint32_t getTexture();

        float posX, posY, posZ;
        float rotX, rotY, rotZ;

    private:
        uint32_t vertices;
        uint32_t vao;
        uint32_t texture;
        uint32_t triangles;

};