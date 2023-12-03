#pragma once
// Includes
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

// Engine
#include "Engine/Engine.h"

// This header contains a bunch of physics related stuff
namespace Physics {

    struct AABB {
        float x1, y1, z1;
        float x2, y2, z2;
        bool intersects(AABB other);
    };

}