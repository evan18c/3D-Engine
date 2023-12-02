#pragma once
// Includes
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {

    public:
        Camera(float _posX, float _posY, float _posZ, float _lookAtX, float _lookAtY, float _lookAtZ);
        void update();

        bool controlsMouse;
        bool controlsKeyboard;
        float posX, posY, posZ;
        float lookAtX, lookAtY, lookAtZ;
    
    private:
        float lastTime;
        float yaw, pitch;
        float sensitivity;
        float speed;

};