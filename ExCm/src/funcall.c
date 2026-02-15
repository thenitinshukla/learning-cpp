#include <stdio.h>
#include <stdlib.h>

// Function to initialize a matrix
void allocateMatrix(double *matrix, int rows, int cols, double value) {
    #pragma acc kernels
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
		    matrix[i * cols + j] = value;
        }
    }
}

// Function to print a matrix 

void printMatrix(double *matrix, int rows, int cols)
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
            		printf("%f ", matrix[i * cols + j]); // Use %f for floating-point numbers
        }
        printf("\n");
    }
}


// Function to free memory allocated for a matrix
void deallocate(double *matrix) {
    free(matrix);
}
