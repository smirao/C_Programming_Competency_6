#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../head/matrixutils.h"

// Define the value of a matrix entry
typedef long double matrix_type;

// Define constant enums for simple 
typedef const enum {ADD=1, SUBTRACT=2, MULTIPLY=3, ROTATE_LEFT=4, ROTATE_RIGHT=5, ROTATE_TWICE=6} MODES;

// Define Matrix itself
struct Matrix
{
    int rows;
    int columns;
    matrix_type* matrix2dArray;
    bool sparse;
};

// Simplify matrix initiation 
typedef struct Matrix Matrix;


int get_matrix_rows(Matrix* matrix)
{
    // Simply return number of rows
    return matrix->rows;
}


int get_matrix_columns(Matrix* matrix)
{
    // Simply return number of columns
    return matrix->columns;
}


matrix_type get_matrix_index(Matrix* matrix, int row, int column)
{
    if (row < 0 || row >= matrix->rows || column < 0 || column >= matrix->columns)
    {
        printf("Invalid Indexing Range\nERR: get_matrix_index\n\n");
        return 1;
    }
    else 
    {
        return *( matrix->matrix2dArray + row * matrix->columns + column);
    }
}


matrix_type *get_matrix_row(Matrix* matrix, int index)
{
    return get_row(matrix, index);
}


matrix_type *get_matrix_column(Matrix* matrix, int index)
{
   return get_column(matrix, index);
}


bool matricies_match(Matrix* matrix_1, Matrix* matrix_2)
{
    // Check to see if the rows and columns match
    if (!((matrix_1->rows == matrix_2->rows) && (matrix_1->columns == matrix_2->columns)))
    {
        return false;
    }

    // Check each element to see if the same if not return false
    for (int i = 0; i < matrix_1->rows * matrix_1->columns; i++)
    {
        if (*(matrix_1->matrix2dArray + i) != *(matrix_2->matrix2dArray + i))
        {
            return false;
        }
    }

    // Return true if all checks pass
    return true;
}


Matrix* matrix_init(int rows, int columns, matrix_type array_2d[rows][columns])
{
    // Create new matrix struct
    Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));

    // Create new array for the matrix's built in matrix2dArray value
    matrix->matrix2dArray = (matrix_type*)malloc((rows * columns) * sizeof(matrix_type));

    // Add rows and columns 
    matrix->rows = rows;
    matrix->columns = columns;

    int index = 0;
    // itterate through 2dArray's rows and colums
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            // append to matrix 
            *(matrix->matrix2dArray + index++) = (matrix_type)array_2d[i][j];
        }
    }
    return matrix;
}


Matrix* empty_matrix_init(int rows, int columns)
{
    // Create new matrix struct
    Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));

    // Create new array for the matrix's built in matrix2dArray value
    matrix->matrix2dArray = (matrix_type*)calloc((rows * columns), sizeof(matrix_type));

    // Add rows and columns 
    matrix->rows = rows;
    matrix->columns = columns;

    return matrix;
}


Matrix* subset_matrix_init(Matrix* matrix, int uppermost_row_index, int lowermost_row_index, int leftmost_column_index, int rightmost_column_index)
{
    if (lowermost_row_index < uppermost_row_index || rightmost_column_index < leftmost_column_index)
    {
        printf("err1\n");
        return NULL;
    } 
    
    else if (lowermost_row_index - uppermost_row_index < 0 || rightmost_column_index - leftmost_column_index < 0)
    {
        printf("err2\n");
        return NULL;
    }

    else if (uppermost_row_index < 0 || rightmost_column_index < 0 || lowermost_row_index > matrix->rows - 1 || rightmost_column_index > matrix->columns - 1)
    {
        printf("err3\n");
        return NULL;
    }

    else
    {
        matrix_type *new_matrix2dArray = (matrix_type*)calloc((lowermost_row_index - uppermost_row_index + 1) * (rightmost_column_index - leftmost_column_index + 1), sizeof(matrix_type));
        Matrix* new_matrix = empty_matrix_init((lowermost_row_index - uppermost_row_index + 1), (rightmost_column_index - leftmost_column_index + 1));
        int index = 0;
        for (int i = uppermost_row_index; i < lowermost_row_index + 1; i++)
        {
            for (int j = leftmost_column_index; j < rightmost_column_index + 1; j++)
            {
                *(new_matrix2dArray + index++) = get_matrix_index(matrix, i, j);
            }
        }

        new_matrix->matrix2dArray = new_matrix2dArray;
        new_matrix->rows = (lowermost_row_index - uppermost_row_index + 1);
        new_matrix->columns = (rightmost_column_index - leftmost_column_index + 1);
        return new_matrix;
    }
}


Matrix *duplicate_matrix(Matrix* matrix)
{
    // Create new empty matrix
    Matrix *new_matrix = empty_matrix_init(matrix->rows, matrix-> columns);

    // Iterate through riws and columns of both matricies copying from original to new
    for (int i = 0; i < matrix->rows * matrix->columns; i++){
        *(new_matrix->matrix2dArray + i) = *(matrix->matrix2dArray + i);
    }

    return new_matrix;
}


Matrix* matrix_arithmatic(Matrix* matrix_1, Matrix* matrix_2, int mode)
{
    switch (mode)
    {
        // ADD and SUBTRACT follow same line of logic
        case ADD: 
        case SUBTRACT:

            // Check to see if matricies are the same size
            if (matrix_1->columns != matrix_2->columns && matrix_1->rows != matrix_2->rows)
            {
                printf("WARNING: dimension size(s) of the two matricies do not match\nReturning Function...");
                exit(1);
            } 
            // Otherwise proceed with operation
            else 
            {
                // initiate an empty matrix
                Matrix* new_matrix = empty_matrix_init(matrix_1->rows, matrix_1->columns);
                int index;

                // itterate through the matrix going through each row and column individually
                for (int i = 0; i < matrix_1->rows; i++)
                {
                    for (int j = 0; j < matrix_1->columns; j++)
                    {
                        // memory is stored sequentially so treat 2D array as an array of size l x w
                        index = i * matrix_1->rows + j;
                        if (mode == ADD)
                        {
                            *(new_matrix->matrix2dArray + index) = *(matrix_1->matrix2dArray + index) + *(matrix_2->matrix2dArray + index);
                        } 
                        else if (mode == SUBTRACT)
                        {
                            *(new_matrix->matrix2dArray + index) = *(matrix_1->matrix2dArray + index) - *(matrix_2->matrix2dArray + index);
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
                printf("WARNING: the column count of matrix one and the row count of matrix two does not match.\nReturning Function...");
                exit(1);
            } 
            // Otherwise proceed with operation
            else 
            {
                // initiate an empty matrix
                Matrix* new_matrix = empty_matrix_init(matrix_1->rows, matrix_2->columns);

                // For each row in matrix_1 go through each column in matrix_2, multiply and add to new matrix dimensions
                for (int i = 0; i < matrix_1->rows; i++)
                {
                    matrix_type* row = get_matrix_row(matrix_1, i);
                    for (int j = 0; j < matrix_2->columns; j++)
                    {
                        matrix_type* column = get_matrix_column(matrix_2, j);
                        matrix_type new_element = multiply_and_summate(row, column, matrix_1->columns);
                        *(new_matrix->matrix2dArray + (new_matrix->columns * i + j)) = new_element;

                    }
                }
                return new_matrix;
            }
        break;
        default:
            printf("Invalid Mode Selection\nERR: matrix_arithmatic\n\n");
    }

}


void set_matrix_index(Matrix* matrix, int row, int column, matrix_type value)
{
    if (row < 0 || row >= matrix->rows || column < 0 || column >= matrix->columns)
    {
        printf("Invalid Indexing Range\nERR: set_matrix_index\n\n");
    }
    else 
    {
        *( matrix->matrix2dArray + row * matrix->columns + column) = value;
    }
}


void resize_matrix(Matrix* matrix, int uppermost_row_index, int lowermost_row_index, int leftmost_column_index, int rightmost_column_index)
{
    Matrix* tmp_matrix = subset_matrix_init(matrix, uppermost_row_index, lowermost_row_index, leftmost_column_index, rightmost_column_index);
    free(matrix->matrix2dArray);
    matrix->matrix2dArray = tmp_matrix->matrix2dArray;
    matrix->rows = tmp_matrix->rows;
    matrix->columns = tmp_matrix->columns;

    free(tmp_matrix);
}


void rotate_matrix(Matrix* matrix, MODES mode)
{

    switch (mode){
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
            printf("Invalid Mode Selection\nERR: rotate_matrix\n\n");
    }
}


void print_matrix(Matrix* matrix)
{
    // Value for count of largest amount of numbers left of a decimal
    long long highest_place = 0;

    // Shift through rows i and columns j of matrix
    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->columns; j++)
        {

            // Get length of number to the left of decimal
            long long places = base_10_highest_place(*(matrix->matrix2dArray + (i * matrix->columns + j)));
            
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
            long long whitespace = highest_place - base_10_highest_place(*(matrix->matrix2dArray + (i * matrix->columns + j)));
            
            // If the number in question is not negative, add some whitespace to compansate for possible negative numbers
            if (*(matrix->matrix2dArray + (i * matrix->columns + j)) >= 0){whitespace++;}

            // Print out whitespace
            for (int w = 0; w < whitespace; w++)
            {
                printf(" ");
            }

            // print out number
            printf("%.5Lf ", *(matrix->matrix2dArray + (i * matrix->columns + j)));
        }

        // Right matrix wall and a newline
        printf("|\n");
    }
}

