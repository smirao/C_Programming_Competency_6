#include <stdlib.h>
#include <stdio.h>
#include "../head/matrix.h"

void space(){
    printf("\n\n\n");
}

int main() {
    //https://onlinetools.com/math/generate-random-matrix
    // Finished 
    /*
    matrix_arithmatic
    empty_matrix_init
    matrix_init
    print_matrix
    duplicate_matrix
    */
    long double array_2d[2][2] = {
        {4,-1},
        {2,-1}
    };

    long double array_2d2[2][3] = {
        {3,1,0},
        {2,1,-2},
    };

    Matrix* m1 = matrix_init(2, 2,array_2d);
    Matrix* m2 = duplicate_matrix(m1);

    print_matrix(m1);
    space();
    print_matrix(m2);
    space();

    return 0;
}
