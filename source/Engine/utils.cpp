// Includes
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stdint.h>

// Header
#include "Engine/utils.h"

// Reads a file.
char *readFile(const char *file) {

    // Open File
    FILE *fptr;
    fptr = fopen(file, "r");

    // Get File Size
    fseek(fptr, 0, SEEK_END);
    uint32_t file_size = ftell(fptr);
    rewind(fptr); 
    
    // Allocate Memory and Read File
    char *data = (char *)calloc(file_size + 1, 1);
    fread(data, 1, file_size, fptr);

    // Closing and returning
    fclose(fptr);
    return data;
}

// Reads a BMP file and returns pixel data + dimensions
char *readBMP(const char *file, int *dimensions) {

    // Opening file
    char *contents = readFile(file);

    // Creating variables
    uint32_t imageSize;
    uint32_t width;
    uint32_t height;
    char *data;

    // Reading file
    memcpy(&width, contents + 0x12, 4);
    memcpy(&height, contents + 0x16, 4);
    imageSize = width * height * 3;

    // Reading data
    data = (char *)malloc(imageSize);
    memcpy(data, contents + 0x36, imageSize);
    
    // Updating Values and Returning
    dimensions[0] = width;
    dimensions[1] = height;
    return data;
}