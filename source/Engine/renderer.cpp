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
    
    // Loading 3D vertex shader
    uint32_t vertexShader = glCreateShader(GL_VERTEX_SHADER);
    const char *vsCode = readFile("shaders/vertex.glsl");
    glShaderSource(vertexShader, 1, &vsCode, NULL);
    glCompileShader(vertexShader);

    // Loading 3D fragment shader
    uint32_t fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    const char *fsCode = readFile("shaders/fragment.glsl");
    glShaderSource(fragmentShader, 1, &fsCode, NULL);
    glCompileShader(fragmentShader);

    // Creating Program
    shader = glCreateProgram();
    glAttachShader(shader, vertexShader);
    glAttachShader(shader, fragmentShader);
    glLinkProgram(shader);

    // Loading 2D vertex shader
    uint32_t vertexShader2D = glCreateShader(GL_VERTEX_SHADER);
    const char *vsCode2D = readFile("shaders/vertex2D.glsl");
    glShaderSource(vertexShader2D, 1, &vsCode2D, NULL);
    glCompileShader(vertexShader2D);

    // Loading 2D fragment shader
    uint32_t fragmentShader2D = glCreateShader(GL_FRAGMENT_SHADER);
    const char *fsCode2D = readFile("shaders/fragment2D.glsl");
    glShaderSource(fragmentShader2D, 1, &fsCode2D, NULL);
    glCompileShader(fragmentShader2D);

    // Creating Program
    shader2D = glCreateProgram();
    glAttachShader(shader2D, vertexShader2D);
    glAttachShader(shader2D, fragmentShader2D);
    glLinkProgram(shader2D);

}

// Updates rendering, clears screen
void Renderer::update() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

// Renders a single text element
void Renderer::renderText(Text text) {
    
}

// Renders a single sprite
void Renderer::renderSprite(Sprite sprite) {

    // GL settings
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Specify Shader
    glUseProgram(shader2D);

    // Calculating transform variables
    float x = (float)sprite.posX / (float)Engine::window->getWidth();
    float y = (float)sprite.posY / (float)Engine::window->getHeight();
    float scaleX = (float)sprite.getWidth() / (float)Engine::window->getWidth();
    float scaleY = (float)sprite.getHeight() / (float)Engine::window->getHeight();

    // Uniform transform matrix
    glm::mat4 transformation = glm::scale(glm::translate(glm::mat4(1.0f), glm::vec3(x, y * -1, 0)), glm::vec3(scaleX, scaleY, 1));
    uint32_t transformUniform = glGetUniformLocation(shader2D, "Transformation");
    glUniformMatrix4fv(transformUniform, 1, false, &transformation[0][0]);

    // Uniform texture
    uint32_t texture2d = glGetUniformLocation(shader2D, "texture2d");
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, sprite.getTexture());
    glUniform1i(texture2d, 0);

    // Bind to VAO and draw it
    glBindVertexArray(sprite.getVao());
    glDrawArrays(GL_TRIANGLES, 0, 6);

    // Unbindings
    glBindVertexArray(0);
    glUseProgram(0);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Undo GL Settings
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_BLEND);

}

// Renders a single model
void Renderer::renderModel(Model model) {
    
    // Getting Camera Reference
    Camera *camera = Engine::camera;

    // GL Settings
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    // Specify Shader
    glUseProgram(shader);

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
    glm::vec3 lightVector = glm::vec3(0.75f, 1.0f, 0.50f);
    glUniform3f(lightDirection, lightVector.x, lightVector.y, lightVector.z);

    // Bind VAO, Draw it, Unbind it
    glBindVertexArray(model.getVao());
    glDrawArrays(GL_TRIANGLES, 0, model.getTriangles() * 3);

    // Unbindings
    glBindVertexArray(0);
    glUseProgram(0);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Undo GL settings
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);
}

uint32_t Renderer::getShader() {
    return shader;
}

uint32_t Renderer::getShader2D() {
    return shader2D;
}