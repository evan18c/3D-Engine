#pragma once
// Includes
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

// SDL
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

// Sound object, can be played whenever
class Sound {

    public:
        Sound(const char *file);
        void play();

    private:
        SDL_AudioSpec wavSpec;
        Uint32 wavLength;
        Uint8* wavBuffer;
        SDL_AudioDeviceID deviceId;
        

};