#ifndef EXAMPLE_H
#define EXAMPLE_H

typedef struct Matrix Matrix;
int base_10_highest_place(long double);
long double *get_column(Matrix* matrix, int index);
long double *get_row(Matrix* matrix, int index);
long double multiply_and_summate(long double *row, long double *column, int length);



#endif