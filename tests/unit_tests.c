#include <stdlib.h>
#include <stdio.h>
#include "../head/matrix.h"
#include <assert.h>
#include <unistd.h>


void confirm(char *func)
{
    usleep(50000);
    printf("check: %s \033[1;32mGOOD\033[0m\n\n", func);

}

void check_matricies(char *func, Matrix* m1, Matrix* m2)
{
    assert(
        matricies_match(
            m1, m2
        )
    );
    confirm(func);
}

void unit_test(Matrix* matrix_1, Matrix* matrix_2, Matrix* matrix_3, Matrix* empty, Matrix* added, Matrix* subtracted, Matrix* multiplied, Matrix* shortened, Matrix* rotated)
{

    assert(get_matrix_columns(matrix_1) == 3);
    assert(get_matrix_columns(matrix_2) == 2);
    assert(get_matrix_columns(matrix_3) == 2);
    confirm("get_matrix_columns");


    assert(get_matrix_columns(matrix_1) == 3);
    assert(get_matrix_columns(matrix_2) == 2);
    assert(get_matrix_columns(matrix_3) == 2);
    confirm("get_matrix_rows");


    Matrix* empty_new = empty_matrix_init(3, 3, get_matrix_type(matrix_1));
    check_matricies("empty_matrix_init", empty_new, empty);


    switch(get_matrix_type(matrix_1))
    {
        case INT:
        {
            int* row = (int*)get_matrix_row(matrix_1, 0);
            int row_nums[3] = {-1,-2,-3};
            int* column = (int*)get_matrix_column(matrix_1, 0);
            int column_nums[2] = {-1,-4};

            for (int i = 0; i < get_matrix_columns(matrix_1); i++)
            {
                assert(*(row + i) == row_nums[i]);
            }
            confirm("get_matrix_row");

            for (int i = 0; i < get_matrix_rows(matrix_1); i++)
            {
                assert(*(column + i) == column_nums[i]);
            }
            confirm("get_matrix_column");

            int* value = (int*)calloc(1,sizeof(int));
            *value = 100;
            set_matrix_index(empty_new, 0,0,value);
            confirm("set_matrix_index");

            assert(*(int*)get_matrix_index(empty_new, 0, 0) == 100);
            confirm("get_matrix_index");
            free(row);
            free(column);
            free(value);
        }

        break;
        case LONG_INT:
        {
            long int* row = get_matrix_row(matrix_1, 0);
            long int row_nums[3] = {-1,-2,-3};
            long int* column = get_matrix_column(matrix_1, 0);
            long int column_nums[2] = {-1,-4};

            for (int i = 0; i < get_matrix_columns(matrix_1); i++)
            {

                assert(*(row + i) == row_nums[i]);
            }
            confirm("get_matrix_row");

            for (int i = 0; i < get_matrix_rows(matrix_1); i++)
            {
                assert(*(column + i) == column_nums[i]);
            }
            confirm("get_matrix_column");

            long int* value = (long int*)calloc(1,sizeof(long int));
            *value = 100;
            set_matrix_index(empty_new, 0,0,value);
            confirm("set_matrix_index");

            assert(*(long int*)get_matrix_index(empty_new, 0, 0) == 100);
            confirm("get_matrix_index");
            free(row);
            free(column);
            free(value);
        }

        break;
        case LONG_LONG_INT:
        {
            long long int* row = get_matrix_row(matrix_1, 0);
            long long int row_nums[3] = {-1,-2,-3};
            long long int* column = get_matrix_column(matrix_1, 0);
            long long int column_nums[2] = {-1,-4};

            for (int i = 0; i < get_matrix_columns(matrix_1); i++)
            {
                assert(*(row + i) == row_nums[i]);
            }
            confirm("get_matrix_row");

            for (int i = 0; i < get_matrix_rows(matrix_1); i++)
            {
                assert(*(column + i) == column_nums[i]);
            }
            confirm("get_matrix_column");

            long long int* value = (long long int*)calloc(1,sizeof(long long int));
            *value = 100;
            set_matrix_index(empty_new, 0,0,value);
            confirm("set_matrix_index");

            assert(*(long long int*)get_matrix_index(empty_new, 0, 0) == 100);
            confirm("get_matrix_index");
            free(row);
            free(column);
            free(value);
        }
        break;
        case FLOAT:
        {
            float* row = get_matrix_row(matrix_1, 0);
            float row_nums[3] = {-1,-2,-3};
            float* column = get_matrix_column(matrix_1, 0);
            float column_nums[2] = {-1,-4};

            for (int i = 0; i < get_matrix_columns(matrix_1); i++)
            {
                assert(*(row + i) == row_nums[i]);
            }
            confirm("get_matrix_row");

            for (int i = 0; i < get_matrix_rows(matrix_1); i++)
            {
                assert(*(column + i) == column_nums[i]);
            }
            confirm("get_matrix_column");

            float* value = (float*)calloc(1,sizeof(float));
            *value = 100;
            set_matrix_index(empty_new, 0,0,value);
            confirm("set_matrix_index");

            assert(*(float*)get_matrix_index(empty_new, 0, 0) == 100);
            confirm("get_matrix_index");
            free(row);
            free(column);
            free(value);
        }

        break;
        case DOUBLE:
        {
            double* row = get_matrix_row(matrix_1, 0);
            double row_nums[3] = {-1,-2,-3};
            double* column = get_matrix_column(matrix_1, 0);
            double column_nums[2] = {-1,-4};

            for (int i = 0; i < get_matrix_columns(matrix_1); i++)
            {
                assert(*(row + i) == row_nums[i]);
            }
            confirm("get_matrix_row");

            for (int i = 0; i < get_matrix_rows(matrix_1); i++)
            {
                assert(*(column + i) == column_nums[i]);
            }
            confirm("get_matrix_column");

            double* value = (double*)calloc(1,sizeof(double));
            *value = 100;
            set_matrix_index(empty_new, 0,0,value);
            confirm("set_matrix_index");

            assert(*(double*)get_matrix_index(empty_new, 0, 0) == 100);
            confirm("get_matrix_index");
            free(row);
            free(column);
            free(value);
        }
        break;
        case LONG_DOUBLE:
        {
            long double* row = get_matrix_row(matrix_1, 0);
            long double row_nums[3] = {-1,-2,-3};
            long double* column = get_matrix_column(matrix_1, 0);
            long double column_nums[2] = {-1,-4};

            for (int i = 0; i < get_matrix_columns(matrix_1); i++)
            {
                assert(*(row + i) == row_nums[i]);
            }
            confirm("get_matrix_row");

            for (int i = 0; i < get_matrix_rows(matrix_1); i++)
            {
                assert(*(column + i) == column_nums[i]);
            }
            confirm("get_matrix_column");

            long double* value = (long double*)calloc(1,sizeof(long double));
            *value = 100;
            set_matrix_index(empty_new, 0,0,value);
            confirm("set_matrix_index");

            assert(*(long double*)get_matrix_index(empty_new, 0, 0) == 100);
            confirm("get_matrix_index");
            free(row);
            free(column);
            free(value);
        }

        break;
    }


    Matrix* duplicate = duplicate_matrix(matrix_1);
    check_matricies("duplicate_matrix", duplicate, matrix_1);


    Matrix* added_new = matrix_arithmatic(matrix_3, matrix_2, ADD);
    check_matricies("matrix_arithmatic", added_new, added);


    Matrix* subtracted_new = matrix_arithmatic(matrix_3, matrix_2, SUBTRACT);
    check_matricies("matrix_arithmatic", subtracted_new, subtracted);


    Matrix* multiplied_new = matrix_arithmatic(matrix_1, matrix_2, MULTIPLY);
    check_matricies("matrix_arithmatic", multiplied_new, multiplied);


    rotate_matrix(matrix_3, ROTATE_LEFT);
    check_matricies("rotate_matrix", matrix_3, rotated);
    rotate_matrix(matrix_3, ROTATE_RIGHT);


    Matrix* short_new = subset_matrix_init(matrix_3,1,2,0,1);
    check_matricies("subset_matrix_init", short_new, shortened);


    resize_matrix(matrix_3,1,2,0,1);
    check_matricies("subset_matrix_init", matrix_3, shortened);
}


int main() {
        


    int matrix_1_int[2][3] = {
        {-1, -2, -3},
        {-4, -5, -6},
    };

    int matrix_2_int[3][2] = {
        {2,4},
        {6,8},
        {10,12}
    };

    int matrix_3_int[3][2] = {
        {1,2},
        {3,4},
        {5,6}
    };

    int int_empty[3][3] = {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };

    int int_added[3][2] = {
        {3,6},
        {9,12},
        {15,18}
    };

    int int_subtracted[3][2] = {
        {-1,-2},
        {-3,-4},
        {-5,-6}
    };

    int int_multiplied[2][2] = {
        {-44,-56},
        {-98,-128}
    };

    int int_shortened[2][2] = {
        {3,4},
        {5,6}
    };

    int int_rotated[2][3] = {
        {2, 4, 6},
        {1, 3, 5},
    };


    Matrix* m1_int = matrix_init(2, 3, INT, (void*)&matrix_1_int);
    Matrix* m2_int = matrix_init(3, 2, INT, (void*)&matrix_2_int);
    Matrix* m3_int = matrix_init(3, 2, INT, (void*)&matrix_3_int);
    Matrix* m4_int = matrix_init(3, 3, INT, (void*)&int_empty);
    Matrix* m5_int = matrix_init(3, 2, INT, (void*)&int_added);
    Matrix* m6_int = matrix_init(3, 2, INT, (void*)&int_subtracted);
    Matrix* m7_int = matrix_init(2, 2, INT, (void*)&int_multiplied);
    Matrix* m8_int = matrix_init(2, 2, INT, (void*)&int_shortened);
    Matrix* m9_int = matrix_init(2, 3, INT, (void*)&int_rotated);

    unit_test(m1_int, m2_int, m3_int, m4_int, m5_int, m6_int, m7_int, m8_int, m9_int);



    long int matrix_1_long_int[2][3] = {
        {-1, -2, -3},
        {-4, -5, -6},
    };

    long int matrix_2_long_int[3][2] = {
        {2,4},
        {6,8},
        {10,12}
    };

    long int matrix_3_long_int[3][2] = {
        {1,2},
        {3,4},
        {5,6}
    };

    long int long_int_empty[3][3] = {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };

    long int long_int_added[3][2] = {
        {3,6},
        {9,12},
        {15,18}
    };

    long int long_int_subtracted[3][2] = {
        {-1,-2},
        {-3,-4},
        {-5,-6}
    };

    long int long_int_multiplied[2][2] = {
        {-44,-56},
        {-98,-128}
    };

    long int long_int_shortened[2][2] = {
        {3,4},
        {5,6}
    };

    long int long_int_rotated[2][3] = {
        {2, 4, 6},
        {1, 3, 5},
    };


    Matrix* m1_long_int = matrix_init(2, 3, LONG_INT, (void*)&matrix_1_long_int);
    Matrix* m2_long_int = matrix_init(3, 2, LONG_INT, (void*)&matrix_2_long_int);
    Matrix* m3_long_int = matrix_init(3, 2, LONG_INT, (void*)&matrix_3_long_int);
    Matrix* m4_long_int = matrix_init(3, 3, LONG_INT, (void*)&long_int_empty);
    Matrix* m5_long_int = matrix_init(3, 2, LONG_INT, (void*)&long_int_added);
    Matrix* m6_long_int = matrix_init(3, 2, LONG_INT, (void*)&long_int_subtracted);
    Matrix* m7_long_int = matrix_init(2, 2, LONG_INT, (void*)&long_int_multiplied);
    Matrix* m8_long_int = matrix_init(2, 2, LONG_INT, (void*)&long_int_shortened);
    Matrix* m9_long_int = matrix_init(2, 3, LONG_INT, (void*)&long_int_rotated);

    unit_test(m1_long_int, m2_long_int, m3_long_int, m4_long_int, m5_long_int, m6_long_int, m7_long_int, m8_long_int, m9_long_int);



    long long int matrix_1_long_long_int[2][3] = {
        {-1, -2, -3},
        {-4, -5, -6},
    };

    long long int matrix_2_long_long_int[3][2] = {
        {2,4},
        {6,8},
        {10,12}
    };

    long long int matrix_3_long_long_int[3][2] = {
        {1,2},
        {3,4},
        {5,6}
    };

    long long int long_long_int_empty[3][3] = {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };

    long long int long_long_int_added[3][2] = {
        {3,6},
        {9,12},
        {15,18}
    };

    long long int long_long_int_subtracted[3][2] = {
        {-1,-2},
        {-3,-4},
        {-5,-6}
    };

    long long int long_long_int_multiplied[2][2] = {
        {-44,-56},
        {-98,-128}
    };

    long long int long_long_int_shortened[2][2] = {
        {3,4},
        {5,6}
    };

    long long int long_long_int_rotated[2][3] = {
        {2, 4, 6},
        {1, 3, 5},
    };


    Matrix* m1_long_long_int = matrix_init(2, 3, LONG_LONG_INT, (void*)&matrix_1_long_long_int);
    Matrix* m2_long_long_int = matrix_init(3, 2, LONG_LONG_INT, (void*)&matrix_2_long_long_int);
    Matrix* m3_long_long_int = matrix_init(3, 2, LONG_LONG_INT, (void*)&matrix_3_long_long_int);
    Matrix* m4_long_long_int = matrix_init(3, 3, LONG_LONG_INT, (void*)&long_long_int_empty);
    Matrix* m5_long_long_int = matrix_init(3, 2, LONG_LONG_INT, (void*)&long_long_int_added);
    Matrix* m6_long_long_int = matrix_init(3, 2, LONG_LONG_INT, (void*)&long_long_int_subtracted);
    Matrix* m7_long_long_int = matrix_init(2, 2, LONG_LONG_INT, (void*)&long_long_int_multiplied);
    Matrix* m8_long_long_int = matrix_init(2, 2, LONG_LONG_INT, (void*)&long_long_int_shortened);
    Matrix* m9_long_long_int = matrix_init(2, 3, LONG_LONG_INT, (void*)&long_long_int_rotated);

    unit_test(m1_long_long_int, m2_long_long_int, m3_long_long_int, m4_long_long_int, m5_long_long_int, m6_long_long_int, m7_long_long_int, m8_long_long_int, m9_long_long_int);



    float matrix_1_float[2][3] = {
        {-1, -2, -3},
        {-4, -5, -6},
    };

    float matrix_2_float[3][2] = {
        {2,4},
        {6,8},
        {10,12}
    };

    float matrix_3_float[3][2] = {
        {1,2},
        {3,4},
        {5,6}
    };

    float float_empty[3][3] = {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };

    float float_added[3][2] = {
        {3,6},
        {9,12},
        {15,18}
    };

    float float_subtracted[3][2] = {
        {-1,-2},
        {-3,-4},
        {-5,-6}
    };

    float float_multiplied[2][2] = {
        {-44,-56},
        {-98,-128}
    };

    float float_shortened[2][2] = {
        {3,4},
        {5,6}
    };

    float float_rotated[2][3] = {
        {2, 4, 6},
        {1, 3, 5},
    };


    Matrix* m1_float = matrix_init(2, 3, FLOAT, (void*)&matrix_1_float);
    Matrix* m2_float = matrix_init(3, 2, FLOAT, (void*)&matrix_2_float);
    Matrix* m3_float = matrix_init(3, 2, FLOAT, (void*)&matrix_3_float);
    Matrix* m4_float = matrix_init(3, 3, FLOAT, (void*)&float_empty);
    Matrix* m5_float = matrix_init(3, 2, FLOAT, (void*)&float_added);
    Matrix* m6_float = matrix_init(3, 2, FLOAT, (void*)&float_subtracted);
    Matrix* m7_float = matrix_init(2, 2, FLOAT, (void*)&float_multiplied);
    Matrix* m8_float = matrix_init(2, 2, FLOAT, (void*)&float_shortened);
    Matrix* m9_float = matrix_init(2, 3, FLOAT, (void*)&float_rotated);

    unit_test(m1_float, m2_float, m3_float, m4_float, m5_float, m6_float, m7_float, m8_float, m9_float);



    double matrix_1_double[2][3] = {
        {-1, -2, -3},
        {-4, -5, -6},
    };

    double matrix_2_double[3][2] = {
        {2,4},
        {6,8},
        {10,12}
    };

    double matrix_3_double[3][2] = {
        {1,2},
        {3,4},
        {5,6}
    };

    double double_empty[3][3] = {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };

    double double_added[3][2] = {
        {3,6},
        {9,12},
        {15,18}
    };

    double double_subtracted[3][2] = {
        {-1,-2},
        {-3,-4},
        {-5,-6}
    };

    double double_multiplied[2][2] = {
        {-44,-56},
        {-98,-128}
    };

    double double_shortened[2][2] = {
        {3,4},
        {5,6}
    };

    double double_rotated[2][3] = {
        {2, 4, 6},
        {1, 3, 5},
    };


    Matrix* m1_double = matrix_init(2, 3, DOUBLE, (void*)&matrix_1_double);
    Matrix* m2_double = matrix_init(3, 2, DOUBLE, (void*)&matrix_2_double);
    Matrix* m3_double = matrix_init(3, 2, DOUBLE, (void*)&matrix_3_double);
    Matrix* m4_double = matrix_init(3, 3, DOUBLE, (void*)&double_empty);
    Matrix* m5_double = matrix_init(3, 2, DOUBLE, (void*)&double_added);
    Matrix* m6_double = matrix_init(3, 2, DOUBLE, (void*)&double_subtracted);
    Matrix* m7_double = matrix_init(2, 2, DOUBLE, (void*)&double_multiplied);
    Matrix* m8_double = matrix_init(2, 2, DOUBLE, (void*)&double_shortened);
    Matrix* m9_double = matrix_init(2, 3, DOUBLE, (void*)&double_rotated);

    unit_test(m1_double, m2_double, m3_double, m4_double, m5_double, m6_double, m7_double, m8_double, m9_double);



    long double matrix_1_long_double[2][3] = {
        {-1, -2, -3},
        {-4, -5, -6},
    };

    long double matrix_2_long_double[3][2] = {
        {2,4},
        {6,8},
        {10,12}
    };

    long double matrix_3_long_double[3][2] = {
        {1,2},
        {3,4},
        {5,6}
    };

    long double long_double_empty[3][3] = {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };

    long double long_double_added[3][2] = {
        {3,6},
        {9,12},
        {15,18}
    };

    long double long_double_subtracted[3][2] = {
        {-1,-2},
        {-3,-4},
        {-5,-6}
    };

    long double long_double_multiplied[2][2] = {
        {-44,-56},
        {-98,-128}
    };

    long double long_double_shortened[2][2] = {
        {3,4},
        {5,6}
    };

    long double long_double_rotated[2][3] = {
        {2, 4, 6},
        {1, 3, 5},
    };


    Matrix* m1_long_double = matrix_init(2, 3, LONG_DOUBLE, (void*)&matrix_1_long_double);
    Matrix* m2_long_double = matrix_init(3, 2, LONG_DOUBLE, (void*)&matrix_2_long_double);
    Matrix* m3_long_double = matrix_init(3, 2, LONG_DOUBLE, (void*)&matrix_3_long_double);
    Matrix* m4_long_double = matrix_init(3, 3, LONG_DOUBLE, (void*)&long_double_empty);
    Matrix* m5_long_double = matrix_init(3, 2, LONG_DOUBLE, (void*)&long_double_added);
    Matrix* m6_long_double = matrix_init(3, 2, LONG_DOUBLE, (void*)&long_double_subtracted);
    Matrix* m7_long_double = matrix_init(2, 2, LONG_DOUBLE, (void*)&long_double_multiplied);
    Matrix* m8_long_double = matrix_init(2, 2, LONG_DOUBLE, (void*)&long_double_shortened);
    Matrix* m9_long_double = matrix_init(2, 3, LONG_DOUBLE, (void*)&long_double_rotated);

    unit_test(m1_long_double, m2_long_double, m3_long_double, m4_long_double, m5_long_double, m6_long_double, m7_long_double, m8_long_double, m9_long_double);


    return 0;
}
