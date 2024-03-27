#ifndef MATRIX_H
#define MATRIX_H

#include <stdbool.h>

// Required Vars
typedef struct Matrix Matrix;
typedef long double matrix_type;

// Extra Vars
typedef const enum {ADD=1, SUBTRACT=2, MULTIPLY=3, ROTATE_LEFT=4, ROTATE_RIGHT=5, ROTATE_TWICE=6} MODES;

// Required Functions
Matrix *matrix_init(int rows, int columns, matrix_type array_2d[rows][columns]);
Matrix *subset_matrix_init(Matrix* matrix, int min_rows, int max_rows, int min_columns, int max_columns);
Matrix *duplicate_matrix(Matrix* matrix);
Matrix *matrix_arithmatic(Matrix* matrix_1, Matrix* matrix_2, MODES mode);
int get_matrix_rows(Matrix* matrix);
int get_matrix_columns(Matrix* matrix);
matrix_type get_matrix_index(Matrix* matrix, int row, int column);
matrix_type *get_matrix_row(Matrix* matrix, int index);
matrix_type *get_matrix_column(Matrix* matrix, int index);
bool matricies_match(Matrix* matrix_1, Matrix* matrix_2);
void set_matrix_index(Matrix* matrix, int row, int column, matrix_type value);
void resize_matrix(Matrix* matrix, int uppermost_row_index, int lowermost_row_index, int leftmost_column_index, int rightmost_column_index);
void rotate_matrix(Matrix* matrix, MODES mode);

// Extra Functions
void print_matrix(Matrix* matrix);
matrix_type *arrayify_2d(Matrix* matrix);
Matrix* empty_matrix_init(int rows, int columns);


#endif