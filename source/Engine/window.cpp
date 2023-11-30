// Includes
#include <chrono>
#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

// Header Include
#include "Engine/window.h"

// Constructor
Window::Window(int w, int h, const char *title) {

    // Constructing
    width = w;
    height = h;

    // GLFW and GLEW init
    glfwInit();
    window = glfwCreateWindow(width, height, title, NULL, NULL);
    glfwSetWindowPos(window, 100, 100);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwMakeContextCurrent(window);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    glewExperimental = true;
    glewInit();

    // Last time
    lastTime = glfwGetTime();
}

// This function should be called every frame
void Window::update() {

    // Window update
    glfwSwapBuffers(window);
    glfwPollEvents();

    // Frame update
    fpsTimes.push_back(glfwGetTime());
}

// Check if window should be closed
bool Window::shouldClose() {
    return glfwWindowShouldClose(window);
}

// Check if key is pressed
bool Window::getKey(int keyCode) {
    return (glfwGetKey(window, keyCode) == GLFW_PRESS);
}

uint32_t Window::getWidth() {
    return width;
}

uint32_t Window::getHeight() {
    return height;
}

void Window::getCursor(double *x, double *y) {
    glfwGetCursorPos(window, x, y);
}

void Window::setCursor(double x, double y) {
    glfwSetCursorPos(window, x, y);
}

// Gets time since last frame
float Window::getDeltaTime() {
    float currentTime = glfwGetTime();
    float delta = currentTime - lastTime;
    lastTime = currentTime;
    return delta;
}

void Window::setWindowTitle(const char *title) {
    glfwSetWindowTitle(window, title);
}

void Window::closeWindow() {
    glfwTerminate();
}

uint32_t Window::getFPS() {
    std::vector<float> newFpsTimes;
    uint32_t fps = 0;
    for (int i=0; i<fpsTimes.size(); i++) {
        float current = fpsTimes[i];
        if (glfwGetTime() - current < 1.0f) {
            fps++;
            newFpsTimes.push_back(current);
        }
    }
    return fps;
}

void Window::sleep(float s) {
    uint32_t ms = (uint32_t)(s*1000);
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}