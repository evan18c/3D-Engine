// Includes
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

// Header Include
#include "Engine/Engine.h"

// Engine includes
#include "Engine/window.h"
#include "Engine/renderer.h"

namespace Engine {

    Window *window;
    Renderer *renderer;
    Camera *camera;

    void initialize() {
        window = new Window(800, 600, "Engine");
        renderer = new Renderer();
        camera = new Camera(4.0f, 3.0f, 3.0f, 0.0f, 0.0f, 0.0f);
    }
}