#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

int main()
{
	int rows, cols;
	const double value = 2;

	// Prompt the user to input the number of rows and columns
        printf("Enter the number of rows and cols: ");
        scanf("%d %d", &rows, &cols);

	double *a;

	a = (double *)malloc(rows * cols * sizeof(double));
	allocateMatrix(a, rows, cols, value);

	printf("Initialized matrices:\n");
    	printMatrix(a, rows, cols);

	deallocate(a);
 }
