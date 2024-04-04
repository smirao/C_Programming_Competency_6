#ifndef MATRIXUTILS_H
#define MATRIXUTILS_H

// Define constant enums for types
typedef const enum {INT=7, LONG_INT=8, LONG_LONG_INT=9, FLOAT=10, DOUBLE=11, LONG_DOUBLE=12} types;

// Simplify matrix initiation 
typedef struct Matrix Matrix;

// Define Matrix itself
struct Matrix
{
    int rows;
    int columns;
    int type;
    union matrix2dArray {
        int* INT;
        long int* LONG_INT;
        long long int* LONG_LONG_INT;
        float* FLOAT;
        double* DOUBLE;
        long double* LONG_DOUBLE;
    } matrix2dArray;
};

int base_10_highest_place(void* value, types type);
void rotate_right(Matrix* matrix);
void* get_column(Matrix* matrix, int index);
void* get_row(Matrix* matrix, int index);
void error(char* error, char* function_name);

#endif