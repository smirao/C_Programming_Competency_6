#include <stdlib.h>
#include <stdio.h>
#include "../head/matrix.h"

void space(){
    printf("\n\n\n");
}

int main() {
    long double array_2d[2][2] = {
        {4,-1},
        {2,-1}
    };

    long double array_2d2[2][3] = {
        {3,1,0},
        {2,1,-2},
    };

    Matrix* m1 = matrix_init(2, 2,array_2d);
    Matrix* m2 = matrix_init(2,3,array_2d2);
    Matrix* added = matrix_arithmatic(m1,m2,MULTIPLY);
    print_matrix(m1);
    space();
    print_matrix(m2);
    space();

    print_matrix(added);

    return 0;
}
