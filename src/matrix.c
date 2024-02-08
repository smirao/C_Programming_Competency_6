#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum {ADD=1, SUBTRACT=2, MULTIPLY=3} MODES;

struct Matrix{
    int rows;
    int columns;
    long double* matrix2dArray;
    bool sparse;
};



typedef struct Matrix Matrix;

void print_matrix(Matrix* matrix){
    for (int i = 0; i < matrix->rows; i++){
        printf("| ");
        for (int j = 0; j < matrix->columns; j++){
            printf("%Lf ", *(matrix->matrix2dArray + (i * j + j)));
        }
        printf("|\n");
    }
}

Matrix* matrix_init(int rows, int columns, int array_2d[rows][columns]){
    Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));
    matrix->matrix2dArray = (long double*)malloc((rows * columns) * sizeof(long double));
    matrix->rows = rows;
    matrix->columns = columns;

    int index = 0;
    int empty = 0;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            *(matrix->matrix2dArray + index++) = (int)array_2d[i][j];
            if ((int)array_2d[i][j] == 0) {
                empty++;
            }
        }
    }
    return matrix;
}

Matrix* matrix_manipulation(Matrix* m1, Matrix* m2, int mode){
    switch (mode){
        case ADD: 
            if (m1->columns != m2->columns && m1->rows != m2->rows){
                printf("WARNING: dimension size(s) of the two matricies do not match\nReturning Function...");
                exit(1);
            }
        break;
        case SUBTRACT: 
            if (m1->columns != m2->columns && m1->rows != m2->rows){
                printf("WARNING: dimension size(s) of the two matricies do not match\nReturning Function...");
                exit(1);
            }
        break;
        case MULTIPLY: 

        break;
    }
    return m1;

}