// Includes
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Engine/utils.h"
#include "Engine/Engine.h"

// Header Includes
#include "Engine/renderer.h"

// Initialization Method
Renderer::Renderer() {

    // OpenGL Settings
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glDepthFunc(GL_LESS);
    
    // Loading vertex shader
    uint32_t vertexShader = glCreateShader(GL_VERTEX_SHADER);
    const char *vsCode = readFile("shaders/vertex.glsl");
    glShaderSource(vertexShader, 1, &vsCode, NULL);
    glCompileShader(vertexShader);

    // Loading fragment shader
    uint32_t fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    const char *fsCode = readFile("shaders/fragment.glsl");
    glShaderSource(fragmentShader, 1, &fsCode, NULL);
    glCompileShader(fragmentShader);

    // Creating Program
    shader = glCreateProgram();
    glAttachShader(shader, vertexShader);
    glAttachShader(shader, fragmentShader);
    glLinkProgram(shader);

}

// Updates rendering, clears screen
void Renderer::update() {
    glClearColor(0.5f, 0.5f, 0.5f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

// Renders a single model
void Renderer::renderModel(Model model) {
    
    // Getting Camera Reference
    Camera *camera = Engine::camera;

    // Uniform Model, View, Projection matrices
    glm::mat4 Projection = glm::perspective(glm::radians(45.0f), (float)Engine::window->getWidth()/Engine::window->getHeight(), 0.1f, 100.0f);
    glm::mat4 View = glm::lookAt(glm::vec3(camera->posX,camera->posY,camera->posZ),glm::vec3(camera->lookAtX,camera->lookAtY,camera->lookAtZ),glm::vec3(0,1,0));
    glm::mat4 Model = glm::translate(glm::mat4(1.0f), glm::vec3(model.posX, model.posY, model.posZ));
    uint32_t modelUniform = glGetUniformLocation(shader, "Model");
    uint32_t viewUniform = glGetUniformLocation(shader, "View");
    uint32_t projectionUniform = glGetUniformLocation(shader, "Projection");
    glUniformMatrix4fv(modelUniform, 1, false, &Model[0][0]);
    glUniformMatrix4fv(viewUniform, 1, false, &View[0][0]);
    glUniformMatrix4fv(projectionUniform, 1, false, &Projection[0][0]);

    // Uniform textureSampler
    uint32_t textureSampler = glGetUniformLocation(shader, "textureSampler");
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, model.getTexture());
    glUniform1i(textureSampler, 0);

    // Uniform Diffuse Lighting Direction (lightDirection)
    uint32_t lightDirection = glGetUniformLocation(shader, "lightDirection");
    glm::vec3 lightVector = glm::vec3(0.5f, 1.0f, 0.5f);
    glUniform3f(lightDirection, lightVector.x, lightVector.y, lightVector.z);

    // Specify Shader Program
    glUseProgram(shader);

    // Bind VAO, Draw it, Unbind it
    glBindVertexArray(model.getVao());
    glDrawArrays(GL_TRIANGLES, 0, model.getTriangles() * 3);
    glBindVertexArray(0);

}

uint32_t Renderer::getShader() {
    return shader;
}
