#ifndef EXAMPLE_H
#define EXAMPLE_H

// Define constant enums for modes 
typedef const enum {ADD=1, SUBTRACT=2, MULTIPLY=3, ROTATE_LEFT=4, ROTATE_RIGHT=5, ROTATE_TWICE=6} MODES;

// Define constant enums for typs
typedef const enum {INT=7, LONG_INT=8, LONG_LONG_INT=9, CHAR=10, FLOAT=11, DOUBLE=12, LONG_DOUBLE=13} TYPES;

// Simplify matrix initiation 
typedef struct Matrix Matrix;

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


int base_10_highest_place(long double);
long double multiply_and_summate(matrix_type *row, matrix_type *column, int length);
void rotate_right(Matrix* matrix);
matrix_type *get_column(Matrix* matrix, int index);
matrix_type *get_row(Matrix* matrix, int index);
void error(char* error, char* function_name);

#endif