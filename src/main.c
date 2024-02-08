#include <stdlib.h>
#include <stdio.h>
#include "../include/matrix.h"

int main() {
    int array_2d[3][3] = {
        {2,0,1},
        {0,8,35},
        {34,1,1}
    };

    int array_2d2[3][3] = {
        {1,0,1},
        {0,0,1},
        {1,1,1}
    };

    Matrix* matrix = gen_matrix(3,3,array_2d);
    Matrix* matrix2 = gen_matrix(3,3,array_2d2);
    show_matrix(matrix);
    

    return 0;
}
//17th @ 4pm