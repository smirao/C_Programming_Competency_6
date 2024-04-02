#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define constant enums for modes 
//typedef const enum {ADD=1, SUBTRACT=2, MULTIPLY=3, ROTATE_LEFT=4, ROTATE_RIGHT=5, ROTATE_TWICE=6} MODES;

// Define constant enums for typs
typedef const enum {INT=7, LONG_INT=8, LONG_LONG_INT=9, CHAR=10, FLOAT=11, DOUBLE=12, LONG_DOUBLE=13} TYPES;

// Simplify matrix initiation 

// Define the value of a matrix entry
typedef long double matrix_type;

// Define Matrix itself
struct Matrix
{
    int rows;
    int columns;
    TYPES type;
    matrix_type* matrix2dArray;
};

typedef struct Matrix Matrix;

// Function to print out errors and exit program
void error(char* error, char* function_name)
{
    printf("\033[1;31mWARNING: %s\033[0m\nERROR @ %s\n", error, function_name);
    exit(EXIT_FAILURE);
}



// Function to calculate how many numbers to the left of a decimal
int base_10_highest_place(matrix_type value){
    long long converted = (long long)value;

    // if value is zero only one place to be counted
    if (converted == 0) return 1;

    int places = -1;

    // use integer division to constanly get rid of decimals until value is zero
    while (true){
        if ((int)(converted / (long long)pow(10, ++places)) == 0) break;
    }
    return places;
}


// multiply two arrays and add all values together 
long double multiply_and_summate(matrix_type *row, matrix_type *column, int length)
{
    matrix_type total = 0;
    for (int i = 0; i < length; i++)
    {
        total += (*(column + i) * *(row + i));
    }
    return total;
}


// Get an array of values from matrix row
matrix_type* get_row(Matrix* matrix, int index)
{
     // Check if index is within range
    if (index < 0 || index > matrix->rows - 1)
    {
        error("Index is not within range of rows.", "get_row");
        // The above function exits the program, but the return value is to shut the compiler up about the warnings
        return NULL;
    } 
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

// Get an array of values from matrix column
matrix_type *get_column(Matrix* matrix, int index)
{
    // Check if index is within range
    if (index < 0 || index > matrix->columns - 1)
    {
        error("Index is not within range of columns.", "get_column");
        // The above function exits the program, but the return value is to shut the compiler up about the warnings
        return NULL;
    } 
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


// Rotate a matrix and its values to the right
void rotate_right(Matrix* matrix)
{
    int index = 0;

    // Create new array 
    matrix_type *new_matrix2dArray = (matrix_type*)calloc(matrix->columns*matrix->rows, sizeof(matrix_type));

    // For each column in the matrix, append the reverse of said column to the array
    for (int i = 0; i < matrix->columns; i ++)
    {
        matrix_type *column = get_column(matrix, i);
        for (int j = matrix->rows - 1; j >= 0; j--)
        {
            *(new_matrix2dArray + index++) = *(column + j);
        }
    }

    // free the old data, add the new
    free(matrix->matrix2dArray);
    matrix->matrix2dArray = new_matrix2dArray;
    int tmp = matrix->rows;
    matrix->rows = matrix->columns;
    matrix->columns = tmp;
}