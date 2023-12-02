// Includes
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

// Header
#include "Engine/sound.h"

Sound::Sound(const char *file) {
    SDL_Init(SDL_INIT_AUDIO);
    SDL_LoadWAV(file, &wavSpec, &wavBuffer, &wavLength);
}

void Sound::play() {
    deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
    SDL_QueueAudio(deviceId, wavBuffer, wavLength);
    SDL_PauseAudioDevice(deviceId, 0);
}