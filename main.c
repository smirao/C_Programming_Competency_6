#include <stdlib.h>
#include <stdio.h>
#include "head/matrix.h"

void space(){
    printf("\n\n\n");
}

int main() {
        matrix_type a1b1[1][1] = {
        {10},
    };
    Matrix* m1 = matrix_init(1,1,a1b1);

    matrix_type a1b2[1][2] = {
        {11, 3},
    };
    Matrix* m2 = matrix_init(1,2,a1b2);

    matrix_type a1b3[1][3] = {
        {7, 3, 0},
    };
    Matrix* m3 = matrix_init(1,3,a1b3);

    matrix_type a2b1[2][1] = {
        {-3},
        {-8},
    };
    Matrix* m4 = matrix_init(2,1,a2b1);

    matrix_type a2b2[2][2] = {
        {-6, 9},
        {-6, 9},
    };
    Matrix* m5 = matrix_init(2,2,a2b2);

    matrix_type a2b3[2][3] = {
        {6, -6, 4},
        {4, 8, -3},
    };
    Matrix* m6 = matrix_init(2,3,a2b3);

    matrix_type a3b1[3][1] = {
        {-1},
        {-5},
        {-4},
    };
    Matrix* m7 = matrix_init(3,1,a3b1);

    matrix_type a3b2[3][2] = {
        {8, 5},
        {-7, 0},
        {-6, -4},
    };
    Matrix* m8 = matrix_init(3,2,a3b2);

    matrix_type a3b3[3][3] = {
        {-3, -2, 9},
        {11, 6, -7},
        {-4, 5, -5},
    };
    Matrix* m9 = matrix_init(3,3,a3b3);



    return 0;
}
