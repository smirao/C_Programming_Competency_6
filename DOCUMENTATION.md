# Library Variables
Following are the variable types defined in the header matrix.h −
|No.|Variable & Description|
|-|-|
|1|__Matrix__<br>This is a __struct__ that defines the behavior of a matrix in relation to the matrix.h library. This is the structure returned by the  function __matrix_init__ in the form of a pointer.|


# Library Enumerations
Following are the Enumeration types defined in the header matrix.h −
|No.|Enumeration & Description|
|-|-|
|1|__ADD__<br>This enum has the integer value 1 and is used as a mode option for the function __matrix_arithmatic__ in order to add two matricies.|
|2|__SUBTRACT__<br>This enum has the integer value 2 and is used as a mode option for the function __matrix_arithmatic__ in order to subtract two matricies.|
|3|__MULTIPLY__<br>This enum has the integer value 3 and is used as a mode option for the function __matrix_arithmatic__ in order to multiply two matricies.|
|4|__ROTATE_LEFT__<br>This enum has the integer value 4 and is used as a mode option for the function __rotate_matrix__ in order to rotate a matrix to the left.|
|5|__ROTATE_RIGHT__<br>This enum has the integer value 5 and is used as a mode option for the function __rotate_matrix__ in order to rotate a matrix to the right.|
|6|__ROTATE_TWICE__<br>This enum has the integer value 6 and is used as a mode option for the function __rotate_matrix__ in order to rotate a matrix twice, hence inverting it.|


# Library Functions
Following are the Functions types defined in the header matrix.h −
|No.|Function & Description|
|-|-|
|1|__Matrix \*matrix_init(int rows, int columns, int array_2d\[rows\]\[columns\])__<br>Parameters: <br> __- rows:__ Number of rows<br>__- columns:__|
|2|Matrix \*subset_matrix_init(Matrix\* matrix, int min_rows, int max_rows, int min_columns, int max_columns)<br>|
|3|Matrix \*duplicate_matrix(Matrix\* matrix)<br>|
|4|Matrix \*matrix_arithmatic(MODES mode, Matrix\* matrix_1, Matrix\* matrix_2)<br>|
|5|long double get_matrix_rows(Matrix\* matrix)<br>|
|6|long double get_matrix_columns(Matrix\* matrix)<br>|
|7|long double get_matrix_index(int row, int column)<br>|
|8|long double \*get_matrix_row(Matrix\* matrix, int row)<br>|
|9|long double \*get_matrix_column(Matrix\* matrix, int column)<br>|
|10|bool matricies_match(Matrix\* matrix_1, Matrix\* matrix_2)<br>|
|11|void set_matrix_index(Matrix\* matrix, int row, int column, long double value)<br>|
|12|void resize_matrix(Matrix\* matrix, int min_rows, int max_rows, int min_columns, int max_columns)<br>|
|13|void rotate_matrix(Matrix\* matrix, MODES mode)<br>|
|14|void print_matrix(Matrix\* matrix)<br>|


