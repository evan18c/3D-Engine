// Includes
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Engine/utils.h"

// Include Header
#include "Engine/model.h"

Model::Model(const char *objFile, const char *bmpFile) {

    // Defining Position
    posX = 0.0f;
    posY = 0.0f;
    posZ = 0.0f;
    rotX = 0.0f;
    rotY = 0.0f;
    rotZ = 0.0f;

    // Loading Model
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec2> uvs;
    std::vector<glm::vec3> normals;
    std::vector<uint32_t> vertexIndices;
    std::vector<uint32_t> uvIndices;
    std::vector<uint32_t> normalIndices;

    FILE *file = fopen(objFile, "r");
    while(true) {
        char lineHeader[256];
        uint32_t result = fscanf(file, "%s", lineHeader);
        if (result == EOF) break;

        // Vertex
        if (strcmp(lineHeader, "v")==0) {
            glm::vec3 vertex;
            fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
            vertices.push_back(vertex);
        }

        // UV
        else if (strcmp(lineHeader, "vt")==0) {
            glm::vec2 uv;
            fscanf(file, "%f %f\n", &uv.x, &uv.y);
            uvs.push_back(uv);
        }

        // Normal
        else if (strcmp(lineHeader, "vn")==0) {
            glm::vec3 normal;
            fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
            normals.push_back(normal);
        }

        // Face
        else if (strcmp(lineHeader, "f")==0) {
            uint32_t vi[3], ui[3], ni[3];
            fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vi[0], &ui[0], &ni[0], &vi[1], &ui[1], &ni[1], &vi[2], &ui[2], &ni[2]);
            vertexIndices.push_back(vi[0]);
            vertexIndices.push_back(vi[1]);
            vertexIndices.push_back(vi[2]);
            uvIndices.push_back(ui[0]);
            uvIndices.push_back(ui[1]);
            uvIndices.push_back(ui[2]);
            normalIndices.push_back(ni[0]);
            normalIndices.push_back(ni[1]);
            normalIndices.push_back(ni[2]);
        }
    }


    // Creating data for OpenGL
    float glVertices[vertexIndices.size() * 3];
    float glUVs[uvIndices.size() * 2];
    float glNormals[normalIndices.size() * 3];

    // Loading glVertices and glUVs and glNormals
    int vIndex = 0;
    int uIndex = 0;
    int nIndex = 0;
    for (int i=0; i<vertexIndices.size(); i++) {
        glVertices[vIndex]     = vertices[vertexIndices[i]-1].x;
        glVertices[vIndex + 1] = vertices[vertexIndices[i]-1].y;
        glVertices[vIndex + 2] = vertices[vertexIndices[i]-1].z;
        vIndex += 3;

        glUVs[uIndex]     = uvs[uvIndices[i]-1].x;
        glUVs[uIndex + 1] = uvs[uvIndices[i]-1].y;
        uIndex += 2;

        glNormals[nIndex]     = normals[normalIndices[i]-1].x;
        glNormals[nIndex + 1] = normals[normalIndices[i]-1].y;
        glNormals[nIndex + 2] = normals[normalIndices[i]-1].z;
        nIndex += 3;
    }

    // Defining Triangle count
    triangles = vertexIndices.size();

    // Create and bind VAO
    vao = 0;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // Create VBO for Vertices in layout 0
    uint32_t vbo1;
    glGenBuffers(1, &vbo1);
    glBindBuffer(GL_ARRAY_BUFFER, vbo1);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glVertices), glVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, false, 0, (void *)0);

    // Create VBO for UVs in layout 1
    uint32_t vbo2;
    glGenBuffers(1, &vbo2);
    glBindBuffer(GL_ARRAY_BUFFER, vbo2);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glUVs), glUVs, GL_STATIC_DRAW);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, false, 0, (void *)0);

    // Create VBO for Normals in layout 2
    uint32_t vbo3;
    glGenBuffers(1, &vbo3);
    glBindBuffer(GL_ARRAY_BUFFER, vbo3);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glNormals), glNormals, GL_STATIC_DRAW);
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, false, 0, (void *)0);

    // Reading Texture
    int dimensions[2];
    char *data = readBMP(bmpFile, (int *)&dimensions);

    // Loading Texture into GL_TEXTURE0
    texture = 0;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, dimensions[0], dimensions[1], 0, GL_BGR, GL_UNSIGNED_BYTE, data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}

uint32_t Model::getVao() {
    return vao;
}

uint32_t Model::getTexture() {
    return texture;
}

uint32_t Model::getTriangles() {
    return triangles;
}

