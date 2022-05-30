#include <bits/stdc++.h>

int main(int argc, char* argv[]) {
    int total_sum = 10;
    //  &total_sum is the pointer and memeory of this variable
    std::cout << &total_sum << "\n";

    double* p_x; // p_x is a pointer to a double precision floating
                       //point variable
    int *p_i, j; // p_x, p_y, p_i are pointers, while j is an integer variable.
    // therefore, it is not recommended to use format double *p_x to declare pointer
    // also declare pointer variable, one_per_line

    // Example use of pointers
    
    /*If a variable p_x has been declared as a pointer to a double precision floating point
      number, then it is clearly important to distinguish between: (i) the location of the
      memory to which this pointer points at (denoted by p_x); and (ii) the contents of
      this memory (denoted by *p_x). The asterisk operator in *p_x is called a pointer
      de-reference and can be thought of as the opposite to the & operator
      double y, z; */
    
    double y, z;   // y, z store double precision numbers
    double* p_x;   // p_x stores the address of a double

    z = 3.0;
    p_x = &z;      // p_x stores the address of z
    y = *p_x + 1.0 // *p_x is the contents of the memory
                   // p_x, i.e. the value of z
    
    // Warnings on the Use of Poiters
    double* p_x; // p_x can store the address of a double
                 // precision number - haven't said which address yet
    *p_x = 1.0; // trying to store the value 1.0 in an
                // unspecified memory location
    
    /* 
    In the code above, we haven’t specified the location of the double precision floating
    point variable that p_x points at. It may therefore be pointing at any location in the
    computer’s memory. Changing the contents of an unspecified location in a computer’s
    memory—as is done in line 5 of the code above—clearly has the potential to cause
    problems that may be hard to locate. */

    // This problem can be avoided by the use of the "new" keyword as shown
    // below to allocate a valid memory address to p_x, and the "delete" keyword
    // which releases this memory to be used by other parts of the program
    // when this memory is no longer required.

    double* p_x;    // p_x stores the address of a double
                    // precision floating point number
    
    p_x = new double; // assigns an address to p_x
    *p_x = 1.0;       // stores 1.0 in memory with address p_x
    delete p_x;       // release memory for re-use

    /*A further reason to use pointers with care is shown in the code below. The first
time y is printed (in line 5) it takes the value 3: the second time y is printed (in line 7)
it takes the value 1 even though y is not explicitly altered in the code between these
two lines. This is because the line between the std::cout statements, line 6, has
altered the value of y, possibly unintentionally, by using the pointer variable p_x
(which contains the address of y) to change the value of y.
    */
    double y;
    double* p_x;
    y = 3.0;
    p_x = &y;
    std::cout << "y = " << y << "\n";
    *p_x = 1.0; // This changes the value of y

    std::cout << "y = " << y << "\n";

    // aliasing and pointer aliasing
    /*
    A situation where the contents of the same variable may be accessed using different
    names, such as in the code above, is known as aliasing. In C++, this is most likely to
    happen when pointers are involved, either when two pointers alias the same address
    in memory, or when a pointer references the contents of another variable. When one
    or more pointers allow the same variable to be accessed using different names, the
    aliasing is known as pointer aliasing
    */

    // Dynamic Allocation of Memeory for Arrays
    // The use of pointers to dynamically allocate memory for arrays
    // avoid estimations of the size.

    // A futher use of pointers for dynamically allocating memory is for the
    // efficient storage of irregularly sized arrays. For example a lower triangular matrix.
    // If a lower triangular matrix is stored in an array as described before,
    // we will have to allocate the same number of columns to each row of the matrix.
    // As we know that roughly half these entries are zero, we are being wasteful
    // of computational memory. Dynamic allocation of memory allows us to allocate memory more prudently.

    // Memory can be allocated using the new operator, and deallocated using the delete operator

    double* x;
    double* y;
    x = new double [10]; // x stores the first element of the array
    y = new double [10];
    
    std::cout << x << "\n";
    std::cout << &x[0] << "\n"; //prints the same value
    // the memory allocated to x may be, and should be, deallocated by
    // using the statement below when this array is no longer required.

    for (int i = 0; i < 10; i++) {
        x[i] = ((double)(i));
        y[i] = 2.0 * x[i];
    }
    delete[] x; // always remember free any memory allocated when it is no longer required
    // however, later we develop a class of vectors, we will see that one advantage of writing
    // a class of vectors is that memory allocated to a vector is automatically freed when appropriate

    delete[] y;


    // dynamic memory allocation for a matrix
    int rows = 5; cols = 3;
    double** A;
    A = new double* [rows]; // A contains the address of the pointer A[0]
    for (int i = 0; i < rows; i++) {
        A[i] = new double[cols]; // each A[i] is a pointer, and contains the address of A[i][0]
    } // above is equivalent to double A[5][3]

    // now deallocate memory dynamically
    for (int i = 0; i < rows; i++) {
        delete[] A[i];
    }
    delete[] A;

    // Irregularly Sized Matrices super diagonal matrix
    int** A_ir;
    A_ir = new int* [1000];
    for (int i = 0; i < 1000; i++) {
        A_ir[i] = new int[i+1];
    }

    // deallocate memory
    for (int i = 0; i < 1000; i++) {
        delete[] A_ir[i]
    }
    delete A_ir[];

    // a safe way to program is to test that your variable has been assigned
    // a value as the code fragment below illustrates:
    double* p_x;
    p_x = new double[10000];
    assert(p_x != NULL);
    
    return 0;
}