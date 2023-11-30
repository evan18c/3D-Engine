// Includes
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Engine/Engine.h"

// Header Include
#include "Engine/camera.h"

Camera::Camera(float _posX, float _posY, float _posZ, float _lookAtX, float _lookAtY, float _lookAtZ) {
    posX = _posX;
    posY = _posY;
    posZ = _posZ;
    lookAtX = _lookAtX;
    lookAtY = _lookAtY;
    lookAtZ = _lookAtZ;
    lastTime = glfwGetTime();
    yaw = 3.14f; // forward facing
    pitch = 0.0f;
    sensitivity = 1.0f;
    speed = 5.0f;
    Engine::window->setCursor(Engine::window->getWidth()/2, Engine::window->getHeight()/2); // set cursor to center
}

// Updates camera's position based on input
void Camera::update() {

    // Getting delta time
    float currentTime = glfwGetTime();
    float deltaTime = currentTime - lastTime;
    lastTime = currentTime;

    // ---------- Mouse Movement ---------- //
    double xpos, ypos;
    Engine::window->getCursor(&xpos, &ypos);
    Engine::window->setCursor(Engine::window->getWidth()/2, Engine::window->getHeight()/2);
    yaw   += sensitivity * (Engine::window->getWidth()/2 - xpos) * deltaTime;
    pitch += sensitivity * (Engine::window->getHeight()/2 - ypos) * deltaTime;
    lookAtX = posX + sin(yaw) * cos(pitch);
    lookAtY = posY + sin(pitch);
    lookAtZ = posZ + cos(yaw) * cos(pitch);

    // ---------- Keyboard Movement ---------- //
    glm::vec3 right = glm::vec3(sin(yaw-3.1415926536f/2.0f),0,cos(yaw-3.1415926536f/2.0f));
    glm::vec3 direction = glm::vec3(sin(yaw)*cos(pitch),sin(pitch),cos(yaw)*cos(pitch));
    glm::vec3 up = glm::cross(right, direction);
    glm::vec3 position = glm::vec3(posX, posY, posZ);
    if (Engine::window->getKey(GLFW_KEY_W)) position += direction * deltaTime * speed;
    if (Engine::window->getKey(GLFW_KEY_S)) position -= direction * deltaTime * speed;
    if (Engine::window->getKey(GLFW_KEY_D)) position += right * deltaTime * speed;
    if (Engine::window->getKey(GLFW_KEY_A)) position -= right * deltaTime * speed;
    if (Engine::window->getKey(GLFW_KEY_SPACE)) position += glm::vec3(0.0f,1.0,0.0f) * deltaTime * speed;
    if (Engine::window->getKey(GLFW_KEY_LEFT_SHIFT)) position -= glm::vec3(0.0f,1.0,0.0f) * deltaTime * speed;
    posX = position.x;
    posY = position.y;
    posZ = position.z;
}