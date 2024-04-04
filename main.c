#include <stdlib.h>
#include <stdio.h>
#include "head/matrix.h"


int main()
{
    long double matrix[2][2] = {
        {1,2},
        {3,4}
    };
    
    Matrix* m1 = matrix_init(2,2, LONG_DOUBLE, (void*)&matrix);

    print_matrix(m1);
    return 0;
}