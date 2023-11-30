#pragma once
// Includes
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class Window {
    public:
        Window(int width, int height, const char *title);
        void update();
        bool shouldClose();
        bool getKey(int keyCode);
        uint32_t getWidth();
        uint32_t getHeight();
        void getCursor(double *x, double *y);
        void setCursor(double x, double y);
        float getDeltaTime();
        void setWindowTitle(const char *title);
        void closeWindow();
        uint32_t getFPS();
        void sleep(float s);

    private:
        uint32_t width, height;
        GLFWwindow *window;
        float lastTime;
        std::vector<float> fpsTimes;
};