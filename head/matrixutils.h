#ifndef EXAMPLE_H
#define EXAMPLE_H

typedef struct Matrix Matrix;
typedef long double matrix_type;

int base_10_highest_place(long double);
long double multiply_and_summate(long double *row, long double *column, int length);
void rotate_right(Matrix* matrix);
matrix_type *get_column(Matrix* matrix, int index);
matrix_type *get_row(Matrix* matrix, int index);

#endif