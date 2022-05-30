#include <iostream>
#include <cmath>

double CalculateMinimum(double a, double b); // function prototype
void PrintPassOrFail(int score, int passMark); // no returned value
double** AllocateMatrixMemory(int numRows, int numCols);
void FreeMatrixMemory(int numRows, double** matrix);

// Use of Pointers as Function Arguments (one way to return mul values via directly accessing address)
void CalculateRealAndImaginary(double r, double theta, double* preal, double* pImaginary);

 // Sending Arrays to Functions
/*When sending arrays to functions—whether or not the memory has been allocated
dynamically—it should be noted that it is the address of the first element of the array
that is being sent to the function. In common with sending the pointer to a variable
to a function, changes to this address will not have an effect in the code from which
this function is called: however, the contents of this address—that is, the contents of
the array—may be changed. As such, any changes made to an array inside a function
will have an effect when that variable is used subsequently outside the function. 
*/
void DoSomething(double u[], double A[][10], double B[10][10]);

int main(int argc, char* argv[]) {
    double x = 4.0, y = -8.0;
    double minimum_value = CalculateMinimum(x, y);
    std::cout << "The minimum of " << x << " and " << y
              << " is " << minimum_value << "\n";
    
    int score = 29, pass_mark = 30;
    PrintPassOrFail(score, pass_mark);

    // Returning Pointer Variables From a Function
    double** A;
    A = AllocateMatrixMemory(5, 3);
    A[0][1] = 2.0;
    A[4][2] = 4.0;
    FreeMatrixMemory(5, A);

    // Use of Pointers as Function Arguments
    double r = 3.4;
    double theta = 1.23;
    double x_, y_;
    CalculateRealAndImaginary(r, theta, &x_, &y_);
    std::cout << "Real part = " << x_ << "\n";
    std::cout << "Imaginary part = " << y_ << "\n";

    // Sending Arrays to Functions
    double u[5], A[10][10], B[10][10];

    DoSomething(u, A, B);
    // This will print the values allocated in
    // the function DoSomething
    std::cout << u[2] << "\n";
    std::cout << A[2][3] << "\n";
    std::cout << B[3][3] << "\n";

    return 0;
}

double CalculateMinimum(double a, double b) {
    double minimum;
    if (a < b) {
        minimum = a;
    } else {
        minimum = b;
    }
    return minimum;
}

void PrintPassOrFail(int score, int passMark) {
    if (score >= passMark) {
        std::cout << "Pass - congratulations!\n";
    } else {
        std::cout << "Fail - better luck next time!\n";
    }
}

// Function to allocate memory for a matrix dynamically
double** AllocateMatrixMemory(int numRows, int numCols) {
    double** matrix;
    matrix = new double* [numRows];
    for (int i = 0; i < numRows; i++) {
        matrix[i] = new double [numCols];
    }
    return matrix;
}

// Function to free memory of a matrix
void FreeMatrixMemory(int numRows, double** matrix) {
    for (int i = 0; i < numRows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void CalculateRealAndImaginary(double r, double theta, double* pReal, double* pImaginary) {
    *pReal = r*cos(theta);
    *pImaginary = r*sin(theta);
}

void DoSomething(double u[], double A[][10], double B[10][10]) {
    u[2] = 1.0;
    A[2][3] = 4.0;
    B[3][3] = -90.6;
}
