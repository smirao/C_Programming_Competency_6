#ifndef EXAMPLE_H
#define EXAMPLE_H

struct Matrix;
typedef struct Matrix Matrix;
typedef enum {ADD=1, SUBTRACT=2, MULTIPLY=3} MODES;
void show_matrix(Matrix* matrix);
Matrix* gen_matrix(int rows, int columns, int array_2d[rows][columns]);


#endif