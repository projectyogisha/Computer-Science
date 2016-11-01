#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define SUCCESS 1
#define FAILURE 0

#define IN
#define OUT

#define ROUND_FACTOR 100
#define N 4 /*size of the matrix*/

int gaussian_elimination (float **matrix, int row, int col);
void display_matrix (float **matrix, int row, int col);

#endif
