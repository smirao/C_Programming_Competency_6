#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../head/matrixutils.h"

typedef enum {ADD=1, SUBTRACT=2, MULTIPLY=3} MODES;

struct Matrix
{
    int rows;
    int columns;
    long double* matrix2dArray;
    bool sparse;
};

typedef struct Matrix Matrix;
















void print_matrix(Matrix* matrix)
{
    long long highest_place = 0;

    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->columns; j++)
        {
            long long places = base_10_highest_place(*(matrix->matrix2dArray + (i * matrix->columns + j)));
            if (highest_place < places)
            {
                highest_place = places;
            }
        }
    }

    for (int i = 0; i < matrix->rows; i++)
    {
        printf("| ");
        for (int j = 0; j < matrix->columns; j++)
        {
            
            long long whitespace = highest_place - base_10_highest_place(*(matrix->matrix2dArray + (i * matrix->columns + j)));
            for (int w = 0; w < whitespace; w++)
            {
                printf(" ");
            }
            printf("%.5Lf ", *(matrix->matrix2dArray + (i * matrix->columns + j)));
        }
        printf("|\n");
    }
}


















Matrix* matrix_init(int rows, int columns, long double array_2d[rows][columns])
{
    Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));
    matrix->matrix2dArray = (long double*)malloc((rows * columns) * sizeof(long double));
    matrix->rows = rows;
    matrix->columns = columns;

    int index = 0;
    int empty = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            *(matrix->matrix2dArray + index++) = (long double)array_2d[i][j];
            if ((long double)array_2d[i][j] == 0) 
            {
                empty++;
            }
        }
    }
    return matrix;
}




















Matrix* empty_matrix_init(int rows, int columns)
{
    Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));
    matrix->matrix2dArray = (long double*)malloc((rows * columns) * sizeof(long double));
    matrix->rows = rows;
    matrix->columns = columns;

    int index = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            *(matrix->matrix2dArray + index++) = 0;
        }
    }
    return matrix;
}


















Matrix* matrix_arithmatic(Matrix* matrix_1, Matrix* matrix_2, int mode)
{
    switch (mode)
    {
        // ADD and SUBTRACT follow same line of logic
        case ADD: 
        case SUBTRACT:

            // Check to see if matricies are the same size
            if (matrix_1->columns != matrix_2->columns && matrix_1->rows != matrix_2->rows)
            {
                printf("WARNING: dimension size(s) of the two matricies do not match\nReturning Function...");
                exit(1);
            } 
            // Otherwise proceed with operation
            else 
            {
                // initiate an empty matrix
                Matrix* new_matrix = empty_matrix_init(matrix_1->rows, matrix_1->columns);
                int index;

                // itterate through the matrix going through each row and column individually
                for (int i = 0; i < matrix_1->rows; i++)
                {
                    for (int j = 0; j < matrix_1->columns; j++)
                    {
                        // memory is stored sequentially so treat 2D array as an array of size l x w
                        index = i * matrix_1->rows + j;
                        if (mode == ADD)
                        {
                            *(new_matrix->matrix2dArray + index) = *(matrix_1->matrix2dArray + index) + *(matrix_2->matrix2dArray + index);
                        } 
                        else if (mode == SUBTRACT)
                        {
                            *(new_matrix->matrix2dArray + index) = *(matrix_1->matrix2dArray + index) - *(matrix_2->matrix2dArray + index);
                        }
                    }
                }
                return new_matrix;
            }
        break;
        case MULTIPLY: 

            // Check to see if columns of matrix_1 are equal to the rows in matrix_2
            if (matrix_1->columns != matrix_2->rows)
            {
                printf("WARNING: the column count of matrix one and the row count of matrix two does not match.\nReturning Function...");
                exit(1);
            } 
            // Otherwise proceed with operation
            else 
            {
                // initiate an empty matrix
                Matrix* new_matrix = empty_matrix_init(matrix_1->rows, matrix_2->columns);
                for (int i = 0; i < matrix_1->rows; i++)
                {
                    long double* row = get_row(matrix_1, i);
                    for (int j = 0; j < matrix_2->columns; j++)
                    {
                        long double* column = get_column(matrix_2, j);
                        long double new_element = multiply_and_summate(row, column, matrix_1->columns);
                        *(new_matrix->matrix2dArray + (new_matrix->columns * i + j)) = new_element;

                    }
                }
                return new_matrix;
            }
        break;
        default:
            exit(1);
    }

}















