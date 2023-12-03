// Includes
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Engine/Engine.h"

// Header
#include "Engine/physics.h"

// This header contains a bunch of physics related stuff
namespace Physics {

    bool AABB::intersects(AABB other) {
        if (x2 < other.x1 || x1 > other.x2) return false;
        if (y2 < other.y1 || y1 > other.y2) return false;
        if (z2 < other.z1 || z1 > other.z2) return false;
        return true;
    }

}