#pragma once
// Includes
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stdint.h>

char *readFile(const char *file);
char *readBMP(const char *file, int *dimensions);