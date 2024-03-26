#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Matrix
{
    int rows;
    int columns;
    long double* matrix2dArray;
    bool sparse;
};

typedef struct Matrix Matrix;

int base_10_highest_place(long double value){
    long long converted = (long long)value;
    
    if (converted == 0) return 1;

    int places = 0;
    while (1){
        if (converted / (long long)pow(10, places++) == 0) break;
    }
    return places -1;
}

long double *get_column(Matrix* matrix, int index){
    if (index < 0 || index > matrix->columns - 1){
        exit(1);
    } else {
        long double* array = (long double*)calloc(matrix->rows, sizeof(long double));
        for (int i = 0; i < matrix->rows; i++){
            *(array + i) = *( matrix->matrix2dArray +  (index + matrix->columns * i));

        }
        return array;
    }
}

long double *get_row(Matrix* matrix, int index){
    if (index < 0 || index > matrix->rows - 1){
        exit(1);
    } else {
        long double* array = (long double*)calloc(matrix->columns, sizeof(long double));
        for (int i = 0; i < matrix->columns; i++){
            *(array + i) = *( matrix->matrix2dArray + index * matrix->columns + i);
        }

        return array;
    }
}

long double multiply_and_summate(long double *row, long double *column, int length)
{
    long double total = 0;
    for (int i = 0; i < length; i++)
    {
        total += (*(column + i) * *(row + i));
    }
    return total;
}
//Matrix* add_matricies(){}

//Matrix* subtract_matricies(){}

//Matrix* multiply_matricies(){}