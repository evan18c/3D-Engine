#pragma once
// Includes
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stdint.h>

// File reading functions
char *readFile(const char *file);
char *readBMP(const char *file, int *dimensions);

// Some useful constants
const float quadVerticesTriangulated[] = {
    -1, -1,  0,
     1,  1,  0,
    -1,  1,  0,
    -1, -1,  0,
     1, -1,  0,
     1,  1,  0
};

const float quadUVsTriangulated[] = {
    0, 0,
    1, 1,
    0, 1,
    0, 0,
    1, 0,
    1, 1
};