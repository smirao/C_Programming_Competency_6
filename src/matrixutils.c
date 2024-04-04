#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define constant enums for types
typedef const enum {INT=7, LONG_INT=8, LONG_LONG_INT=9, FLOAT=10, DOUBLE=11, LONG_DOUBLE=12} types;

// Simplify matrix initiation 
typedef struct Matrix Matrix;

// Define Matrix itself
struct Matrix
{
    int rows;
    int columns;
    int type;
    union matrix2dArray {
        int* INT;
        long int* LONG_INT;
        long long int* LONG_LONG_INT;
        float* FLOAT;
        double* DOUBLE;
        long double* LONG_DOUBLE;
    } matrix2dArray;
};


// Function to print out errors and exit program
void error(char* error, char* function_name)
{
    printf("\033[1;31mWARNING: %s\033[0m\nERROR @ %s\n", error, function_name);
    exit(EXIT_FAILURE);
}


// Function to calculate how many numbers to the left of a decimal
int base_10_highest_place(void* value, types type)
{
    // if value is zero only one place to be counted
    if (value == 0) return 1;

    int places = -1;

    switch (type)
    {
        case INT:
        case LONG_INT:
        case LONG_LONG_INT:
        {
            long long converted = *(size_t*)value;

            // use integer division to constanly get rid of decimals until value is zero
            while (true)
            {
                if (((int)converted / (long long)pow(10, ++places)) == 0) break;
            }
            return places;
        }
        break;
        
        case FLOAT:
        case DOUBLE: 
        case LONG_DOUBLE:
        {
            long double converted = *(long double*)value;

            // use integer division to constanly get rid of decimals until value is zero
            while (true)
            {
                if (((int)converted / (long long)pow(10, ++places)) == 0) break;
            }
            return places;
        }
        break;
        default:
            error("Something went horribly wrong lol.", "base_10_highest_place");
            return -1;
    }
    return -1;
}


// Get an array of values from matrix row
void* get_row(Matrix* matrix, int index)
{
     // Check if index is within range
    if (index < 0 || index > matrix->rows - 1)
    {
        error("Index is not within range of rows.", "get_row");
        // The above function exits the program, but the return value is to shut the compiler up about the warnings
        return NULL;
    } 
    else 
    {
        // Create new long double array representing a column and shift through requested column and append to new array
        switch (matrix->type)
        {
            case INT:
            {
                int* array = (int*)calloc(matrix->columns, sizeof(int));

                for (int i = 0; i < matrix->columns; i++)
                {
                    *(array + i) = *( matrix->matrix2dArray.INT + index * matrix->columns + i);
                }

                return array;
            }
            break;

            case LONG_INT:
            {
                long int* array = (long int*)calloc(matrix->columns, sizeof(long int));
                for (int i = 0; i < matrix->columns; i++)
                {
                    *(array + i) = *( matrix->matrix2dArray.LONG_INT + index * matrix->columns + i);
                }

                return array;
            }
            break;
            
            case LONG_LONG_INT:
            {
                long long int* array = (long long int*)calloc(matrix->columns, sizeof(long long int));

                for (int i = 0; i < matrix->columns; i++)
                {
                    *(array + i) = *( matrix->matrix2dArray.LONG_LONG_INT + index * matrix->columns + i);
                }

                return array;
            }
            break;
            
            case FLOAT:
            {
                float* array = (float*)calloc(matrix->columns, sizeof(float));

                for (int i = 0; i < matrix->columns; i++)
                {
                    *(array + i) = *( matrix->matrix2dArray.FLOAT + index * matrix->columns + i);
                }

                return array;
            }
            break;
            
            case DOUBLE:
            {
                double* array = (double*)calloc(matrix->columns, sizeof(double));

                for (int i = 0; i < matrix->columns; i++)
                {
                    *(array + i) = *( matrix->matrix2dArray.DOUBLE + index * matrix->columns + i);
                }

                return array;
            }
            break;
        
            case LONG_DOUBLE:
            {
                
                long double* array = (long double*)calloc(matrix->columns, sizeof(long double));

                for (int i = 0; i < matrix->columns; i++)
                {
                    *(array + i) = *( matrix->matrix2dArray.LONG_DOUBLE + index * matrix->columns + i);
                }

                return array;
            }
            break;
            default:
                error("Something went horribly wrong lol.", "get_row");
                return NULL;
        }
    }
    return NULL;
}


// Get an array of values from matrix column
void* get_column(Matrix* matrix, int index)
{
    // Check if index is within range
    if (index < 0 || index > matrix->columns - 1)
    {
        error("Index is not within range of columns.", "get_column");
        // The above function exits the program, but the return value is to shut the compiler up about the warnings
        return NULL;
    } 
    else 
    {
         // Create new long double array representing a column and shift through requested column and append to new array
        switch (matrix->type)
        {
            case INT:
            {
                int* array = (int*)calloc(matrix->rows, sizeof(int));

                for (int i = 0; i < matrix->rows; i++)
                {
                    *(array + i) = *(matrix->matrix2dArray.INT +  (matrix->columns * i + index));
                }

                return array;
            }
            break;

            case LONG_INT:
            {
                long int* array = (long int*)calloc(matrix->rows, sizeof(long int));

                for (int i = 0; i < matrix->rows; i++)
                {
                    *(array + i) = *(matrix->matrix2dArray.LONG_INT +  (matrix->columns * i + index));
                }

                return array;
            }
            break;
            
            case LONG_LONG_INT:
            {
                long long int* array = (long long int*)calloc(matrix->rows, sizeof(long long int));

                for (int i = 0; i < matrix->rows; i++)
                {
                    *(array + i) = *(matrix->matrix2dArray.LONG_LONG_INT +  (matrix->columns * i + index));
                }

                return array;
            }
            break;
            
            case FLOAT:
            {
                float* array = (float*)calloc(matrix->rows, sizeof(float));

                for (int i = 0; i < matrix->rows; i++)
                {
                    *(array + i) = *(matrix->matrix2dArray.FLOAT +  (matrix->columns * i + index));
                }

                return array;
            }
            break;
            
            case DOUBLE:
            {
                double* array = (double*)calloc(matrix->rows, sizeof(double));

                for (int i = 0; i < matrix->rows; i++)
                {
                    *(array + i) = *(matrix->matrix2dArray.DOUBLE +  (matrix->columns * i + index));
                }

                return array;
            }
            break;
        
            case LONG_DOUBLE:
            {
                long double* array = (long double*)calloc(matrix->rows, sizeof(long double));

                for (int i = 0; i < matrix->rows; i++)
                {
                    *(array + i) = *(matrix->matrix2dArray.LONG_DOUBLE +  (matrix->columns * i + index));
                }

                return array;
            }
            break;
            default:
                error("Something went horribly wrong lol.", "get_row");
                return NULL;
        }
    }
    return NULL;
}


// Rotate a matrix and its values to the right
void rotate_right(Matrix* matrix)
{
    int index = 0;

    // Create new array and for each column in the matrix, append the reverse of said column to the array

    switch (matrix->type)
    {
        case INT:
        {
            int *new_matrix2dArray = (int*)calloc(matrix->columns*matrix->rows, sizeof(int));

            for (int i = 0; i < matrix->columns; i ++)
            {
                int *column = (int*)get_column(matrix, i);
                for (int j = matrix->rows - 1; j >= 0; j--)
                {
                    *(new_matrix2dArray + index++) = *(column + j);
                }
            }
            free(matrix->matrix2dArray.INT);
            matrix->matrix2dArray.INT = new_matrix2dArray;
        }
        break;

        case LONG_INT:
        {
            long int *new_matrix2dArray = (long int*)calloc(matrix->columns*matrix->rows, sizeof(long int));

            for (int i = 0; i < matrix->columns; i ++)
            {
                long int *column = (long int*)get_column(matrix, i);
                for (int j = matrix->rows - 1; j >= 0; j--)
                {
                    *(new_matrix2dArray + index++) = *(column + j);
                }
            }
            free(matrix->matrix2dArray.LONG_INT);
            matrix->matrix2dArray.LONG_INT = new_matrix2dArray;
        }
        break;
        
        case LONG_LONG_INT:
        {
            long long int *new_matrix2dArray = (long long int*)calloc(matrix->columns*matrix->rows, sizeof(long long int));

            for (int i = 0; i < matrix->columns; i ++)
            {
                long long int *column = (long long int*)get_column(matrix, i);
                for (int j = matrix->rows - 1; j >= 0; j--)
                {
                    *(new_matrix2dArray + index++) = *(column + j);
                }
            }
            free(matrix->matrix2dArray.LONG_LONG_INT);
            matrix->matrix2dArray.LONG_LONG_INT = new_matrix2dArray;
        }
        break;
        
        case FLOAT:
        {
            float *new_matrix2dArray = (float*)calloc(matrix->columns*matrix->rows, sizeof(float));

            for (int i = 0; i < matrix->columns; i ++)
            {
                float *column = (float*)get_column(matrix, i);
                for (int j = matrix->rows - 1; j >= 0; j--)
                {
                    *(new_matrix2dArray + index++) = *(column + j);
                }
            }
            free(matrix->matrix2dArray.FLOAT);
            matrix->matrix2dArray.FLOAT = new_matrix2dArray;
        }
        break;
        
        case DOUBLE:
        {
            double *new_matrix2dArray = (double*)calloc(matrix->columns*matrix->rows, sizeof(double));

            for (int i = 0; i < matrix->columns; i ++)
            {
                double *column = (double*)get_column(matrix, i);
                for (int j = matrix->rows - 1; j >= 0; j--)
                {
                    *(new_matrix2dArray + index++) = *(column + j);
                }
            }
            free(matrix->matrix2dArray.DOUBLE);
            matrix->matrix2dArray.DOUBLE = new_matrix2dArray;
        }
        break;
        
        case LONG_DOUBLE:
        {
            long double *new_matrix2dArray = (long double*)calloc(matrix->columns*matrix->rows, sizeof(long double));

            for (int i = 0; i < matrix->columns; i ++)
            {
                long double *column = (long double*)get_column(matrix, i);
                for (int j = matrix->rows - 1; j >= 0; j--)
                {
                    *(new_matrix2dArray + index++) = *(column + j);
                }
            }
            free(matrix->matrix2dArray.LONG_DOUBLE);
            matrix->matrix2dArray.LONG_DOUBLE = new_matrix2dArray;
        }
        break;
    }

    // free the old data, add the new
    int tmp = matrix->rows;
    matrix->rows = matrix->columns;
    matrix->columns = tmp;
}