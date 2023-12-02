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
        return false;
    }

}