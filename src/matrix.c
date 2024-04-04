#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../head/matrixutils.h"

// Define constant enums for modes 
typedef const enum {ADD=1, SUBTRACT=2, MULTIPLY=3, ROTATE_LEFT=4, ROTATE_RIGHT=5, ROTATE_TWICE=6} MODES;

// Return number of rows in matrix
int get_matrix_rows(Matrix* matrix)
{
    return matrix->rows;
}


// Return number of columns in matrix
int get_matrix_columns(Matrix* matrix)
{
    return matrix->columns;
}


// Return int value associated with matrix type
int get_matrix_type(Matrix* matrix)
{
    return matrix->type;
}

// Returns Value found at the intersection of (row, column)
void* get_matrix_index(Matrix* matrix, int row, int column)
{
    // Check to make sure that row/column is within bounds
    if (row < 0 || row >= matrix->rows || column < 0 || column >= matrix->columns)
    {
        error("Invalid Indexing Range", "get_matrix_index");
        // The above function exits the program, but the return value is to shut the compiler up about the warnings
        return NULL;
    }
    else 
    {
        // Return value found at (row, column) in matrix
        switch (matrix->type)
        {
            case INT:
            {
                return matrix->matrix2dArray.INT + row * matrix->columns + column;
            }
            break;

            case LONG_INT:
            {
                return matrix->matrix2dArray.LONG_INT + row * matrix->columns + column;
            }
            break;
            
            case LONG_LONG_INT:
            {
                return matrix->matrix2dArray.LONG_LONG_INT + row * matrix->columns + column;
            }
            break;
            
            case FLOAT:
            {
                return matrix->matrix2dArray.FLOAT + row * matrix->columns + column;
            }
            break;
            
            case DOUBLE:
            {
                return matrix->matrix2dArray.DOUBLE + row * matrix->columns + column;
            }
            break;
        
            case LONG_DOUBLE:
                return matrix->matrix2dArray.LONG_DOUBLE + row * matrix->columns + column;
            break;
            default:
                error("Something went horribly wrong lol.", "get_matrix_index");
                return NULL;
        }
        
    }
}


// Get an array of values from matrix row
void* get_matrix_row(Matrix* matrix, int index)
{
    return get_row(matrix, index);
}


// Get an array of values from matrix column
void* get_matrix_column(Matrix* matrix, int index)
{
   return get_column(matrix, index);
}


// Return boolean based on if matricies match
bool matricies_match(Matrix* matrix_1, Matrix* matrix_2)
{
    if (matrix_1->type != matrix_2->type)
    {
        error("Matricies have conflicting types", "matricies_match");
        return false;
    }

    // Check to see if the rows and columns match
    if (!((matrix_1->rows == matrix_2->rows) && (matrix_1->columns == matrix_2->columns)))
    {
        return false;
    }

    // Check each element to see if the same if not return false
    for (int i = 0; i < matrix_1->rows * matrix_1->columns; i++)
    {
        // return false if values are not equal 
        switch (matrix_1->type)
        {
            case INT:
            {
                if (*(matrix_1->matrix2dArray.INT + i) != *(matrix_2->matrix2dArray.INT + i)){return false;}
            }
            break;

            case LONG_INT:
            {
                if (*(matrix_1->matrix2dArray.LONG_INT + i) != *(matrix_2->matrix2dArray.LONG_INT + i)){return false;}
            }
            break;
            
            case LONG_LONG_INT:
            {
                if (*(matrix_1->matrix2dArray.LONG_LONG_INT + i) != *(matrix_2->matrix2dArray.LONG_LONG_INT + i)){return false;}
            }
            break;
            
            case FLOAT:
            {
                if (*(matrix_1->matrix2dArray.FLOAT + i) != *(matrix_2->matrix2dArray.FLOAT + i)){return false;}
            }
            break;
            
            case DOUBLE:
            {
                if (*(matrix_1->matrix2dArray.DOUBLE + i) != *(matrix_2->matrix2dArray.DOUBLE + i)){return false;}
            }
            break;
        
            case LONG_DOUBLE:
                if (*(matrix_1->matrix2dArray.LONG_DOUBLE + i) != *(matrix_2->matrix2dArray.LONG_DOUBLE + i)){return false;}
            break;
        }
    }

    // Return true if all checks pass
    return true;
}


// Return matrix generated from 2d array
Matrix* matrix_init(int rows, int columns, types type, void* array_2d)
{
    // Create new matrix struct
    Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));

    // Create new array for the matrix's built in matrix2dArray value
    switch (type)
    {
        case INT:
        {
            matrix->matrix2dArray.INT = (int*)malloc((rows * columns) * sizeof(int));
        }
        break;

        case LONG_INT:
        {
            matrix->matrix2dArray.LONG_INT = (long int*)malloc((rows * columns) * sizeof(long int));
        }
        break;
        
        case LONG_LONG_INT:
        {
            matrix->matrix2dArray.LONG_LONG_INT = (long long int*)malloc((rows * columns) * sizeof(long long int));
        }
        break;
        
        case FLOAT:
        {
            matrix->matrix2dArray.FLOAT = (float*)malloc((rows * columns) * sizeof(float));
        }
        break;
        
        case DOUBLE:
        {
            matrix->matrix2dArray.DOUBLE = (double*)malloc((rows * columns) * sizeof(double));
        }
        break;
        
        case LONG_DOUBLE:
            matrix->matrix2dArray.LONG_DOUBLE = (long double*)malloc((rows * columns) * sizeof(long double));
        break;
    }

    // Add rows and columns 
    matrix->rows = rows;
    matrix->columns = columns;
    matrix->type = type;

    // index varable is used to easily index 2d array as a 1d bc memory is continuous
    int index = 0;

    // itterate through 2dArray's rows and colums add values to matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            switch (type)
            {
                case INT:
                {
                    *(matrix->matrix2dArray.INT + index) = *((int*)array_2d + index);
                }
                break;

                case LONG_INT:
                {
                    *(matrix->matrix2dArray.LONG_INT + index) = *((long int*)array_2d + index);
                }
                break;
                
                case LONG_LONG_INT:
                {
                    *(matrix->matrix2dArray.LONG_LONG_INT + index) = *((long long int*)array_2d + index);
                }
                break;
                
                case FLOAT:
                {
                    *(matrix->matrix2dArray.FLOAT + index) = *((float*)array_2d + index);
                }
                break;
                
                case DOUBLE:
                {
                    *(matrix->matrix2dArray.DOUBLE + index) = *((double*)array_2d + index);
                }
                break;
        
                case LONG_DOUBLE:
                {
                    *(matrix->matrix2dArray.LONG_DOUBLE + index) = *((long double*)array_2d + index);
                }
                break;
            }
            index++;
        }
    }
    return matrix;
}


// Return empty matrix based on dimensional imput
Matrix* empty_matrix_init(int rows, int columns, types type)
{
    // Create new matrix struct
    Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));

    // Create new array for the matrix's built in matrix2dArray value
    switch (type)
    {
        case INT:
        {
            matrix->matrix2dArray.INT = (int*)calloc((rows * columns), sizeof(int));
        }
        break;

        case LONG_INT:
        {
            matrix->matrix2dArray.LONG_INT = (long int*)calloc((rows * columns), sizeof(long int));
        }
        break;
        
        case LONG_LONG_INT:
        {
            matrix->matrix2dArray.LONG_LONG_INT = (long long int*)calloc((rows * columns), sizeof(long long int));
        }
        break;
        
        case FLOAT:
        {
            matrix->matrix2dArray.FLOAT = (float*)calloc((rows * columns), sizeof(float));
        }
        break;
        
        case DOUBLE:
        {
            matrix->matrix2dArray.DOUBLE = (double*)calloc((rows * columns), sizeof(double));
        }
        break;
        
        case LONG_DOUBLE:
            matrix->matrix2dArray.LONG_DOUBLE = (long double*)calloc((rows * columns), sizeof(long double));
        break;
    }

    // Add rows and columns 
    matrix->rows = rows;
    matrix->columns = columns;
    matrix->type = type;

    return matrix;
}


// Returns a subset of a matrix based on predefined ranges
Matrix* subset_matrix_init(Matrix* matrix, int uppermost_row_index, int lowermost_row_index, int leftmost_column_index, int rightmost_column_index)
{
    if (lowermost_row_index < uppermost_row_index || rightmost_column_index < leftmost_column_index)
    {
        error("The indexs are switched.", "ERR: subset_matrix_init");
        // The above function exits the program, but the return value is to shut the compiler up about the warnings
        return NULL;
    } 
    
    else if (lowermost_row_index - uppermost_row_index < 0 || rightmost_column_index - leftmost_column_index < 0)
    {
        error("The indexs are switched.", "subset_matrix_init");
        // The above function exits the program, but the return value is to shut the compiler up about the warnings
        return NULL;
    }

    else if (uppermost_row_index < 0 || rightmost_column_index < 0 || lowermost_row_index > matrix->rows - 1 || rightmost_column_index > matrix->columns - 1)
    {
        error("The index is out of range.", "subset_matrix_init");
        // The above function exits the program, but the return value is to shut the compiler up about the warnings
        return NULL;
    }

    else
    {
        // index varable is used to easily index 2d array as a 1d bc memory is continuous
        Matrix* new_matrix = empty_matrix_init((lowermost_row_index - uppermost_row_index + 1), (rightmost_column_index - leftmost_column_index + 1), matrix->type);
        int index = 0;

        // create new array adding values within specified range 
        switch (matrix->type)
        {
            case INT:
            {
                int *new_matrix2dArray = (int*)calloc((lowermost_row_index - uppermost_row_index + 1) * (rightmost_column_index - leftmost_column_index + 1), sizeof(int));
                for (int i = uppermost_row_index; i < lowermost_row_index + 1; i++)
                {
                    for (int j = leftmost_column_index; j < rightmost_column_index + 1; j++)
                    {
                        *(new_matrix2dArray + index++) = *(int*)get_matrix_index(matrix, i, j);
                    }
                }
                new_matrix->matrix2dArray.INT = new_matrix2dArray;
            }
            break;

            case LONG_INT:
            {
                long int *new_matrix2dArray = (long int*)calloc((lowermost_row_index - uppermost_row_index + 1) * (rightmost_column_index - leftmost_column_index + 1), sizeof(long int));
                for (int i = uppermost_row_index; i < lowermost_row_index + 1; i++)
                {
                    for (int j = leftmost_column_index; j < rightmost_column_index + 1; j++)
                    {
                        *(new_matrix2dArray + index++) = *(long int*)get_matrix_index(matrix, i, j);
                    }
                }
                new_matrix->matrix2dArray.LONG_INT = new_matrix2dArray;
            }
            break;
            
            case LONG_LONG_INT:
            {
                long long int *new_matrix2dArray = (long long int*)calloc((lowermost_row_index - uppermost_row_index + 1) * (rightmost_column_index - leftmost_column_index + 1), sizeof(long long int));
                for (int i = uppermost_row_index; i < lowermost_row_index + 1; i++)
                {
                    for (int j = leftmost_column_index; j < rightmost_column_index + 1; j++)
                    {
                        *(new_matrix2dArray + index++) = *(long long int*)get_matrix_index(matrix, i, j);
                    }
                }
                new_matrix->matrix2dArray.LONG_LONG_INT = new_matrix2dArray;
            }
            break;
            
            case FLOAT:
            {
                float *new_matrix2dArray = (float*)calloc((lowermost_row_index - uppermost_row_index + 1) * (rightmost_column_index - leftmost_column_index + 1), sizeof(float));
                for (int i = uppermost_row_index; i < lowermost_row_index + 1; i++)
                {
                    for (int j = leftmost_column_index; j < rightmost_column_index + 1; j++)
                    {
                        *(new_matrix2dArray + index++) = *(float*)get_matrix_index(matrix, i, j);
                    }
                }
                new_matrix->matrix2dArray.FLOAT = new_matrix2dArray;
            }
            break;
            
            case DOUBLE:
            {
                double *new_matrix2dArray = (double*)calloc((lowermost_row_index - uppermost_row_index + 1) * (rightmost_column_index - leftmost_column_index + 1), sizeof(double));
                for (int i = uppermost_row_index; i < lowermost_row_index + 1; i++)
                {
                    for (int j = leftmost_column_index; j < rightmost_column_index + 1; j++)
                    {
                        *(new_matrix2dArray + index++) = *(double*)get_matrix_index(matrix, i, j);
                    }
                }
                new_matrix->matrix2dArray.DOUBLE = new_matrix2dArray;
            }
            break;
        
            case LONG_DOUBLE:
            {
                long double *new_matrix2dArray = (long double*)calloc((lowermost_row_index - uppermost_row_index + 1) * (rightmost_column_index - leftmost_column_index + 1), sizeof(long double));
                for (int i = uppermost_row_index; i < lowermost_row_index + 1; i++)
                {
                    for (int j = leftmost_column_index; j < rightmost_column_index + 1; j++)
                    {
                        *(new_matrix2dArray + index++) = *(long double*)get_matrix_index(matrix, i, j);
                    }
                }
                new_matrix->matrix2dArray.LONG_DOUBLE = new_matrix2dArray;
            }
            break;
        }
        
        // insert data into new matrix and return
        new_matrix->rows = (lowermost_row_index - uppermost_row_index + 1);
        new_matrix->columns = (rightmost_column_index - leftmost_column_index + 1);
        return new_matrix;
    }
}


// returns duplicate of matrix
Matrix* duplicate_matrix(Matrix* matrix)
{
    // Create new empty matrix
    Matrix *new_matrix = empty_matrix_init(matrix->rows, matrix->columns, matrix->type);

    // Iterate through riws and columns of both matricies copying from original to new
    for (int i = 0; i < matrix->rows * matrix->columns; i++)
    {
        // Add values to new matrix
        switch (matrix->type)
        {
            case INT:
            {
                *(new_matrix->matrix2dArray.INT + i) = *(matrix->matrix2dArray.INT + i);
            }
            break;

            case LONG_INT:
            {
                *(new_matrix->matrix2dArray.LONG_INT + i) = *(matrix->matrix2dArray.LONG_INT + i);
            }
            break;
            
            case LONG_LONG_INT:
            {
                *(new_matrix->matrix2dArray.LONG_LONG_INT + i) = *(matrix->matrix2dArray.LONG_LONG_INT + i);
            }
            break;
            
            case FLOAT:
            {
                *(new_matrix->matrix2dArray.FLOAT + i) = *(matrix->matrix2dArray.FLOAT + i);
            }
            break;
            
            case DOUBLE:
            {
                *(new_matrix->matrix2dArray.DOUBLE + i) = *(matrix->matrix2dArray.DOUBLE + i);
            }
            break;
        
            case LONG_DOUBLE:
                *(new_matrix->matrix2dArray.LONG_DOUBLE + i) = *(matrix->matrix2dArray.LONG_DOUBLE + i);
            break;
        }
    }

    return new_matrix;
}


// Returns value of some type of matrix arithmatic eg: add, subtract, multiply
Matrix* matrix_arithmatic(Matrix* matrix_1, Matrix* matrix_2, int mode)
{
    Matrix* new_matrix = empty_matrix_init(matrix_1->rows, matrix_2->columns, matrix_1->type);

    switch (mode)
    {
        // ADD and SUBTRACT follow same line of logic
        case ADD: 
        case SUBTRACT:

            // Check to see if matricies are the same size
            if (matrix_1->columns != matrix_2->columns && matrix_1->rows != matrix_2->rows)
            {
                error("Dimension size(s) of the two matricies do not match.", "matrix_arithmatic");
                // The above function exits the program, but the return value is to shut the compiler up about the warnings
                return NULL;
            } 
            else 
            {
                //Matrix* new_matrix = empty_matrix_init(matrix_1->rows, matrix_1->columns, matrix_1->type);
                // index varable is used to easily index 2d array as a 1d bc memory is continuous
                int index = 0;

                // itterate through the matrix going through each row and column individually
                for (int i = 0; i < matrix_1->rows; i++)
                {
                    for (int j = 0; j < matrix_1->columns; j++)
                    {
                        // memory is stored sequentially so treat 2D array as an array of size l x w
                        if (mode == ADD)
                        {
                            switch (matrix_1->type)
                            {
                                case INT:
                                {
                                    *(new_matrix->matrix2dArray.INT + index++) = *(int*)get_matrix_index(matrix_1, i, j) + *(int*)get_matrix_index(matrix_2, i, j);
                                }
                                break;

                                case LONG_INT:
                                {
                                    *(new_matrix->matrix2dArray.LONG_INT + index++) = *(long int*)get_matrix_index(matrix_1, i, j) + *(long int*)get_matrix_index(matrix_2, i, j);
                                }
                                break;
                                
                                case LONG_LONG_INT:
                                {
                                    *(new_matrix->matrix2dArray.LONG_LONG_INT + index++) = *(long long int*)get_matrix_index(matrix_1, i, j) + *(long long int*)get_matrix_index(matrix_2, i, j);
                                }
                                break;
                                
                                case FLOAT:
                                {
                                    *(new_matrix->matrix2dArray.FLOAT + index++) = *(float*)get_matrix_index(matrix_1, i, j) + *(float*)get_matrix_index(matrix_2, i, j);
                                }
                                break;
                                
                                case DOUBLE:
                                {
                                    *(new_matrix->matrix2dArray.DOUBLE + index++) = *(double*)get_matrix_index(matrix_1, i, j) + *(double*)get_matrix_index(matrix_2, i, j);
                                }
                                break;
        
                                case LONG_DOUBLE:
                                    *(new_matrix->matrix2dArray.LONG_DOUBLE + index++) = *(long double*)get_matrix_index(matrix_1, i, j) + *(long double*)get_matrix_index(matrix_2, i, j);
                                break;
                            }
                        } 
                        else if (mode == SUBTRACT)
                        {
                            switch (matrix_1->type)
                            {
                                case INT:
                                {
                                    *(new_matrix->matrix2dArray.INT + index++) = *(int*)get_matrix_index(matrix_1, i, j) - *(int*)get_matrix_index(matrix_2, i, j);
                                }
                                break;

                                case LONG_INT:
                                {
                                    *(new_matrix->matrix2dArray.LONG_INT + index++) = *(long int*)get_matrix_index(matrix_1, i, j) - *(long int*)get_matrix_index(matrix_2, i, j);
                                }
                                break;
                                
                                case LONG_LONG_INT:
                                {
                                    *(new_matrix->matrix2dArray.LONG_LONG_INT + index++) = *(long long int*)get_matrix_index(matrix_1, i, j) - *(long long int*)get_matrix_index(matrix_2, i, j);
                                }
                                break;
                                
                                case FLOAT:
                                {
                                    *(new_matrix->matrix2dArray.FLOAT + index++) = *(float*)get_matrix_index(matrix_1, i, j) - *(float*)get_matrix_index(matrix_2, i, j);
                                }
                                break;
                                
                                case DOUBLE:
                                {
                                    *(new_matrix->matrix2dArray.DOUBLE + index++) = *(double*)get_matrix_index(matrix_1, i, j) - *(double*)get_matrix_index(matrix_2, i, j);
                                }
                                break;
        
                                case LONG_DOUBLE:
                                    *(new_matrix->matrix2dArray.LONG_DOUBLE + index++) = *(long double*)get_matrix_index(matrix_1, i, j) - *(long double*)get_matrix_index(matrix_2, i, j);
                                break;
                            }
                        }
                    }
                }
                return new_matrix;
            }
        break;
        case MULTIPLY: 

            // Check to see if columns of matrix_1 are equal to the rows in matrix_2
            if (matrix_1->columns != matrix_2->rows)
            {
                error("The column count of matrix one and the row count of matrix two does not match.", "matrix_arithmatic");
                // The above function exits the program, but the return value is to shut the compiler up about the warnings
                return NULL;
            } 
            else 
            {

                // For each row in matrix_1 go through each column in matrix_2, multiply and add to new matrix dimensions
                for (int i = 0; i < matrix_1->rows; i++)
                {
                    switch (matrix_1->type)
                    {
                        case INT:
                        {
                            int* row = get_matrix_row(matrix_1, i);
    
                            for (int j = 0; j < matrix_2->columns; j++)
                            {
                                int* column = (int*)get_matrix_column(matrix_2, j);
                                int total = 0;
                                for (int a = 0; a < matrix_1->columns; a++)
                                {
                                    total += *(row + a) * *(column + a);
                                }
                                *(new_matrix->matrix2dArray.INT + (new_matrix->columns * i + j)) = total;

                            }
                        }
                        break;

                        case LONG_INT:
                        {
                            long int* row = get_matrix_row(matrix_1, i);
    
                            for (int j = 0; j < matrix_2->columns; j++)
                            {
                                long int* column = (long int*)get_matrix_column(matrix_2, j);
                                long int total = 0;
                                for (int a = 0; a < matrix_1->columns; a++)
                                {
                                    total += *(row + a) * *(column + a);
                                }
                                *(new_matrix->matrix2dArray.LONG_INT + (new_matrix->columns * i + j)) = total;

                            }
                        }
                        break;
                        
                        case LONG_LONG_INT:
                        {
                            long long int* row = get_matrix_row(matrix_1, i);
    
                            for (int j = 0; j < matrix_2->columns; j++)
                            {
                                long long int* column = (long long int*)get_matrix_column(matrix_2, j);
                                long long int total = 0;
                                for (int a = 0; a < matrix_1->columns; a++)
                                {
                                    total += *(row + a) * *(column + a);
                                }
                                *(new_matrix->matrix2dArray.LONG_LONG_INT + (new_matrix->columns * i + j)) = total;

                            }
                        }
                        break;
                        
                        case FLOAT:
                        {
                            float* row = get_matrix_row(matrix_1, i);
    
                            for (int j = 0; j < matrix_2->columns; j++)
                            {
                                float* column = (float*)get_matrix_column(matrix_2, j);
                                float total = 0;
                                for (int a = 0; a < matrix_1->columns; a++)
                                {
                                    total += *(row + a) * *(column + a);
                                }
                                *(new_matrix->matrix2dArray.FLOAT + (new_matrix->columns * i + j)) = total;

                            }
                        }
                        break;
                        
                        case DOUBLE:
                        {
                            double* row = get_matrix_row(matrix_1, i);
    
                            for (int j = 0; j < matrix_2->columns; j++)
                            {
                                double* column = (double*)get_matrix_column(matrix_2, j);
                                double total = 0;
                                for (int a = 0; a < matrix_1->columns; a++)
                                {
                                    total += *(row + a) * *(column + a);
                                }
                                *(new_matrix->matrix2dArray.DOUBLE + (new_matrix->columns * i + j)) = total;

                            }
                        }
                        break;
        
                        case LONG_DOUBLE:
                        {
                            long double* row = get_matrix_row(matrix_1, i);
    
                            for (int j = 0; j < matrix_2->columns; j++)
                            {
                                long double* column = get_matrix_column(matrix_2, j);
                                long double total = 0;
                                for (int a = 0; a < matrix_1->columns; a++)
                                {
                                    total += *(row + a) * *(column + a);
                                }
                                *(new_matrix->matrix2dArray.LONG_DOUBLE + (new_matrix->columns * i + j)) = total;

                            }
                        }
                        break;
                    }
                    
                }
                return new_matrix;
            }
        break;
        default:
            error( "Invalid Mode Selection.", "matrix_arithmatic");
            // The above function exits the program, but the return value is to shut the compiler up about the warnings
            return NULL;
    }

}


// Set vale of matrix at (row, column)
void set_matrix_index(Matrix* matrix, int row, int column, void* value)
{
    // Check if row and column selection is within range
    if (row < 0 || row >= matrix->rows || column < 0 || column >= matrix->columns)
    {
        error("Invalid Indexing Range", "set_matrix_index");
    }
    else 
    {
        // Dereference and assign value
        switch (matrix->type)
        {
            case INT:
            {
                *( matrix->matrix2dArray.INT + row * matrix->columns + column) = *(int*)value;
            }
            break;

            case LONG_INT:
            {
                *( matrix->matrix2dArray.LONG_INT + row * matrix->columns + column) = *(long int*)value;
            }
            break;
            
            case LONG_LONG_INT:
            {
                *( matrix->matrix2dArray.LONG_LONG_INT + row * matrix->columns + column) = *(long long int*)value;
            }
            break;
            
            case FLOAT:
            {
                *( matrix->matrix2dArray.FLOAT + row * matrix->columns + column) = *(float*)value;
            }
            break;
            
            case DOUBLE:
            {
                *( matrix->matrix2dArray.DOUBLE + row * matrix->columns + column) = *(double*)value;
            }
            break;
        
            case LONG_DOUBLE:
                *( matrix->matrix2dArray.LONG_DOUBLE + row * matrix->columns + column) = *(long double*)value;
            break;
        }
    }
}


// Resize the matrix to a particular 
void resize_matrix(Matrix* matrix, int uppermost_row_index, int lowermost_row_index, int leftmost_column_index, int rightmost_column_index)
{
    // Return a temp subset 
    Matrix* tmp_matrix = subset_matrix_init(matrix, uppermost_row_index, lowermost_row_index, leftmost_column_index, rightmost_column_index);

    switch (matrix->type)
    {
        case INT:
        {
            free(matrix->matrix2dArray.INT);
            // Swap old matrix values with new values
            matrix->matrix2dArray.INT = tmp_matrix->matrix2dArray.INT;
        }
        break;

        case LONG_INT:
        {
            free(matrix->matrix2dArray.LONG_INT);
            // Swap old matrix values with new values
            matrix->matrix2dArray.LONG_INT = tmp_matrix->matrix2dArray.LONG_INT;
        }
        break;
        
        case LONG_LONG_INT:
        {
            free(matrix->matrix2dArray.LONG_LONG_INT);
            // Swap old matrix values with new values
            matrix->matrix2dArray.LONG_LONG_INT = tmp_matrix->matrix2dArray.LONG_LONG_INT;
        }
        break;
        
        case FLOAT:
        {
            free(matrix->matrix2dArray.FLOAT);
            // Swap old matrix values with new values
            matrix->matrix2dArray.FLOAT = tmp_matrix->matrix2dArray.FLOAT;
        }
        break;
        
        case DOUBLE:
        {
            free(matrix->matrix2dArray.DOUBLE);
            // Swap old matrix values with new values
            matrix->matrix2dArray.DOUBLE = tmp_matrix->matrix2dArray.DOUBLE;
        }
        break;
        
        case LONG_DOUBLE:
        {
            free(matrix->matrix2dArray.LONG_DOUBLE);
            // Swap old matrix values with new values
            matrix->matrix2dArray.LONG_DOUBLE = tmp_matrix->matrix2dArray.LONG_DOUBLE;
        }
    }
    matrix->rows = tmp_matrix->rows;
    matrix->columns = tmp_matrix->columns;

    // Free temp subset
    free(tmp_matrix);
}


// Function used to rotate posistion of a matrix
void rotate_matrix(Matrix* matrix, MODES mode)
{

    switch (mode)
    {
        case ROTATE_RIGHT:
            rotate_right(matrix);
        break;
        case ROTATE_TWICE:
            rotate_right(matrix);
            rotate_right(matrix);
        break;
        case ROTATE_LEFT:
            rotate_right(matrix);
            rotate_right(matrix);
            rotate_right(matrix);
        break;
        default:
            error("Invalid Mode Selection", "rotate_matrix");
    }
}


void print_matrix(Matrix* matrix)
{
    if (matrix == NULL)
    {
        error("You cannot pass null pointer to print_matrix", "print_matrix");
    }

    // Value for count of largest amount of numbers left of a decimal
    long long highest_place = 0;

    // Shift through rows i and columns j of matrix
    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->columns; j++)
        {

            // Get length of number to the left of decimal
            int places = 0;

            switch (matrix->type)
            {
                case INT:
                {
                    places = base_10_highest_place((matrix->matrix2dArray.INT + (i * matrix->columns + j)), matrix->type);
                }
                break;

                case LONG_INT:
                {
                    places = base_10_highest_place((matrix->matrix2dArray.LONG_INT + (i * matrix->columns + j)), matrix->type);
                }
                break;
                
                case LONG_LONG_INT:
                {
                    places = base_10_highest_place((matrix->matrix2dArray.LONG_LONG_INT + (i * matrix->columns + j)), matrix->type);
                }
                break;
                
                case FLOAT:
                {
                    places = base_10_highest_place((matrix->matrix2dArray.FLOAT + (i * matrix->columns + j)), matrix->type);
                }
                break;
                
                case DOUBLE:
                {
                    places = base_10_highest_place((matrix->matrix2dArray.DOUBLE + (i * matrix->columns + j)), matrix->type);
                }
                break;
        
                case LONG_DOUBLE:
                    places = base_10_highest_place((matrix->matrix2dArray.LONG_DOUBLE + (i * matrix->columns + j)), matrix->type);
                break;
            }

            
            // Replace number if higher is found
            if (highest_place < places)
            {
                highest_place = places;
            }
        }
    }

    // Shift through rows i and columns j of matrix
    for (int i = 0; i < matrix->rows; i++)
    {
        // Left matrix wall
        printf("| ");

        for (int j = 0; j < matrix->columns; j++)
        {
            // Determine amount of whitespace by subtracting greatest number by length of number to the left of decimal
            int tmp = 0;
            switch (matrix->type)
            {
                case INT:
                {
                    tmp = base_10_highest_place((matrix->matrix2dArray.INT + (i * matrix->columns + j)), matrix->type);
                }
                break;

                case LONG_INT:
                {
                    tmp = base_10_highest_place((matrix->matrix2dArray.LONG_INT + (i * matrix->columns + j)), matrix->type);
                }
                break;
                
                case LONG_LONG_INT:
                {
                    tmp = base_10_highest_place((matrix->matrix2dArray.LONG_LONG_INT + (i * matrix->columns + j)), matrix->type);
                }
                break;
                
                case FLOAT:
                {
                    tmp = base_10_highest_place((matrix->matrix2dArray.FLOAT + (i * matrix->columns + j)), matrix->type);
                }
                break;
                
                case DOUBLE:
                {
                    tmp = base_10_highest_place((matrix->matrix2dArray.DOUBLE + (i * matrix->columns + j)), matrix->type);
                }
                break;
        
                case LONG_DOUBLE:
                    tmp = base_10_highest_place((matrix->matrix2dArray.LONG_DOUBLE + (i * matrix->columns + j)), matrix->type);
                break;
            }
            int whitespace = highest_place - tmp; 

            // If the number in question is not negative, add some whitespace to compansate for possible negative numbers
            if (tmp >= 0){whitespace++;}

            // Print out whitespace
            for (int w = 0; w < whitespace; w++)
            {
                printf(" ");
            }

            // print out number
            switch (matrix->type)
            {
                case INT:
                {
                    printf("%d ", *(matrix->matrix2dArray.INT + (i * matrix->columns + j)));
                }
                break;

                case LONG_INT:
                {
                    printf("%ld ", *(matrix->matrix2dArray.LONG_INT + (i * matrix->columns + j)));
                }
                break;
                
                case LONG_LONG_INT:
                {
                    printf("%lld ", *(matrix->matrix2dArray.LONG_LONG_INT + (i * matrix->columns + j)));
                }
                break;
                
                case FLOAT:
                {
                    printf("%.5f ", *(matrix->matrix2dArray.FLOAT + (i * matrix->columns + j)));
                }
                break;
                case DOUBLE:
                {
                    printf("%.5f ", *(matrix->matrix2dArray.DOUBLE + (i * matrix->columns + j)));
                }
                break;
        
                case LONG_DOUBLE:
                    printf("%.5Lf ", *(matrix->matrix2dArray.LONG_DOUBLE + (i * matrix->columns + j)));
                break;
            }
        }

        // Right matrix wall and a newline
        printf("|\n");
    }
}
