#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <stdbool.h>

// Required Vars
typedef struct Matrix Matrix;

// Extra Vars
typedef const enum {ADD=1, SUBTRACT=2, MULTIPLY=3, ROTATE_LEFT=4, ROTATE_RIGHT=5, ROTATE_TWICE=6} MODES;

// Required Functions
Matrix *matrix_init(int rows, int columns, int array_2d[rows][columns]);
Matrix *subset_matrix_init(Matrix* matrix, int min_rows, int max_rows, int min_columns, int max_columns);
Matrix *duplicate_matrix(Matrix* matrix);
Matrix *matrix_arithmatic(MODES mode, Matrix* matrix_1, Matrix* matrix_2);
long double get_matrix_rows(Matrix* matrix);
long double get_matrix_columns(Matrix* matrix);
long double get_matrix_index(int row, int column);
long double *get_matrix_row(Matrix* matrix, int row);
long double *get_matrix_column(Matrix* matrix, int column);
bool matricies_match(Matrix* matrix_1, Matrix* matrix_2);
void set_matrix_index(Matrix* matrix, int row, int column, long double value);
void resize_matrix(Matrix* matrix, int min_rows, int max_rows, int min_columns, int max_columns);
void rotate_matrix(Matrix* matrix, MODES mode);

// Extra Functions
void print_matrix(Matrix* matrix);

#endif