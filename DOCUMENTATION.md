# Library Variables
Following are the variable types defined in the header matrix.h −
|No.|Variable & Description|
|-|-|
|1|__Matrix__<br>This is a __struct__ that defines the behavior of a matrix in relation to the matrix.h library. This is the structure returned by the  function __matrix_init__ in the form of a pointer.|
|2|__matrix_type__<br>This is a numerical type that defines the the values inside a matrix and its behavior is normally that of a __long double__ in order to preserve accuracy of the matricies.|



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
|1|__int get_matrix_rows(Matrix* matrix)__<br>Parameters: <br> __- matrix:__ Given Matrix struct|
|2|__int get_matrix_columns(Matrix* matrix)__<br>Parameters: <br> __- matrix:__ Given Matrix struct|
|3|__matrix_type get_matrix_index(Matrix* matrix, int row, int column)__<br>Parameters: <br> __- matrix:__ Given Matrix struct|
|4|__matrix_type* get_matrix_row(Matrix\* matrix, int index)__<br>Parameters: <br> __- matrix:__ Given Matrix struct|
|5|__matrix_type* get_matrix_column(Matrix\* matrix, int index)__<br>Parameters: <br> __- matrix:__ Given Matrix struct|
|6|__bool matricies_match(Matrix* matrix_1, Matrix* matrix_2)__<br>Parameters: <br> __- matrix:__ Given Matrix struct|
|7|__Matrix \*matrix_init(int rows, int columns, int array_2d\[rows\]\[columns\])__<br>Parameters: <br> __- rows:__ Number of rows<br>__- columns:__|
|8|__Matrix* empty_matrix_init(int rows, int columns)__<br>Parameters: <br> __- rows:__ Given Matrix struct|
|9|__Matrix* subset_matrix_init(Matrix* matrix, int uppermost_row_index, int lowermost_row_index, int leftmost_column_index, int rightmost_column_index)__<br>|
|10|__Matrix* duplicate_matrix(Matrix* matrix)__<br>Parameters: <br> __- matrix:__ Given Matrix struct|
|11|__Matrix* matrix_arithmatic(Matrix* matrix_1, Matrix* matrix_2, int mode)__<br>|
|12|__void set_matrix_index(Matrix* matrix, int row, int column, matrix_type value)__<br>|
|13|__void resize_matrix(Matrix* matrix, int uppermost_row_index, int lowermost_row_index, int leftmost_column_index, int rightmost_column_index)__<br>|
|14|__void rotate_matrix(Matrix* matrix, MODES mode)__<br>|
|15|__void print_matrix(Matrix* matrix)__<br>|


