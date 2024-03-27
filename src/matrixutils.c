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
typedef long double matrix_type;

int base_10_highest_place(long double value){
    long long converted = (long long)value;
    
    if (converted == 0) return 1;

    int places = 0;

    while (1){
        if (converted / (long long)pow(10, places++) == 0) break;
    }
    return places -1;
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


matrix_type *get_row(Matrix* matrix, int index)
{
     // Check if index is within range
    if (index < 0 || index > matrix->rows - 1)
    {
        printf("Index is not within range of rows.\n");
        exit(1);
    } 
    
    // If not, continue
    else 
    {
        matrix_type* array = (matrix_type*)calloc(matrix->columns, sizeof(matrix_type));

        // shift through requested row and append to new array
        for (int i = 0; i < matrix->columns; i++)
        {
            *(array + i) = *( matrix->matrix2dArray + index * matrix->columns + i);
        }

        return array;
    }
}


matrix_type *get_column(Matrix* matrix, int index)
{
    // Check if index is within range
    if (index < 0 || index > matrix->columns - 1)
    {
        printf("Index is not within range of columns.\n");
        exit(1);
    } 

    // If not, continue
    else 
    {
        // Create new long double array representing a column
        matrix_type* array = (matrix_type*)calloc(matrix->rows, sizeof(matrix_type));

        // shift through requested column and append to new array
        for (int i = 0; i < matrix->rows; i++)
        {
            *(array + i) = *( matrix->matrix2dArray +  (matrix->columns * i + index));
        }

        return array;
    }
}


void rotate_right(Matrix* matrix)
{
    int index = 0;
    matrix_type *new_matrix2dArray = (matrix_type*)calloc(matrix->columns*matrix->rows, sizeof(matrix_type));
    for (int i = 0; i < matrix->columns; i ++)
    {
        matrix_type *column = get_column(matrix, i);
        for (int j = matrix->rows - 1; j >= 0; j--)
        {
            *(new_matrix2dArray + index++) = *(column + j);
        }
    }

    free(matrix->matrix2dArray);
    matrix->matrix2dArray = new_matrix2dArray;
    int tmp = matrix->rows;
    matrix->rows = matrix->columns;
    matrix->columns = tmp;
}