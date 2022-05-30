#include <bits/stdc++.h>
#include<iomanip>
using namespace std;

/*   Function Prototypes  */
//TODO: add another methods for reading data from files and writing output to files
double** AllocateMatrixMemory(int numRows, int numCols);
void FreeMatrixMemory(int numRows, double** matrix);
void inputMatirx(int nRows, int nCols, double** matrix);
void partialPivot(int nRows, int nCols, double** matrix);
void gaussEli(int nRows, int nCols, double** matrix);
void backSub(int nRows, int xCols, double** matrix, double** x);
void printMatrix(int nRows, int nCols, double** matrix);

// Driver class
int main(int argc, char* argv[]) {
    int nCols, nRows;
    int xCols = 1;
    cout.precision(4);  // set precision
    cout.setf(ios::fixed);
    cout<<"\nEnter the no. of equations\n";
    cin>>nRows;  //input the no. of equations
    nCols = nRows + 1; // the last col is the RHS of the equations
    // Allocate memory for the matrix that stores the elements of the augmented-matrix and solns
    double** coeffs, solns;
    coeffs = AllocateMatrixMemory(nRows, nCols);
    solns = AllocateMatrixMemory(nRows, xCols);

    cout<<"\nEnter the elements of the augmented-matrix row-wise:\n";
    intputMatrix(nRows, nCols, coeffs);

    cout<<"\n\nThe matrix after Pivotisation\n";
    partialPivot(nRows, nCols, coeffs);
    printMatrix(nRows, nCols, coeffs);

    cout<<"\n\nThe matrix after gauss-elimination is as follows:\n";
    gaussEli(nRows, nCols, coeffs);
    printMatrix(nRows, nCols, coeffs);

    // Back substitution
    cout<<"\n\nThe values of the variables are as follows:\n";
    void backSub(nRows, xCols, coeffs, solns);
    printMatrix(nRows, xCols, solns);

    // may add write to files etc.
    
    // free memory
    FreeMatrixMemory(nRows, coeffs);
    FreeMatrixMemory(nRows, solns);
    return 0;
}

// Function to print out matrixs in a clear format
void printMatrix(int nRows, int nCols, double** matrix) {
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            cout << matrix[i][j] << setw(16);
        }
        cout<<"\n";
    }
}

// Function to do partial Pivotisation for the augmented coeff matrix
void partialPivot(int nRows, int nCols,  double** matrix) {
    for (int i = 0; i < nRows; i++) {
        for (int k = i+1; k < nRows; k++) {
            if (abs(matrix[i][i]) < abs(matrix[k][i])) {
                for (int j = 0; j < nCols; j++) {
                    double temp = matrix[i][j];
                    matrix[i][j] = matrix[k][j];
                    matrix[k][j] = temp;
                }
            }
        }
    }
}

// Function to do gaussian eliminination
void gaussEli(int nRows, int nCols, double** matrix) {
    for (int i = 0; i < nRows -1; i++) { //loop to perform the gauss elimination
        for (int k = i+1; k < nRows; k++) {
            double t = matrix[k][i] / matrix[i][i];
            for (int j = 0; j < nCols; j++) {
                matrix[k][j] = matrix[k][j] - t * matrix[i][j];  //make the elements below the pivot elements equal to zero or elimnate the variables
            }
        }
    }
}

// Function to do back substitution to get final sols
void backSub(int nRows, int xCols, double** matrix, double** x) {
    for (int i = nRows - 1; i >= 0; i--) {
        x[i][xCols] = matrix[i][nRows]; //make the variable to be calculated equal to the rhs of the last equation
        for (int j = i+1; j < nRows; j++) {
            if (j != i) { //then subtract all the lhs values except the coefficient of the variable whose value is being calculated
                x[i][xCols] = x[i][xCols] - matrix[i][j]*x[j][xCols];
            }
        }
        x[i][xCols] = x[i][xCols] / matrix[i][i];  //now finally divide the rhs by the coefficient of the variable to be calculated
    }
}

// Function to get augmented equations from keyboard
void inputMatirx(int nRows, int nCols, double** matrix) {
    for (int i=0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            cin >> matrix[i][j];
        }
    }
}

// Function to allocate memory for a matrix dynamically
double** AllocateMatrixMemory(int numRows, int numCols) {
    double** matrix;
    matrix = new double* [numRows];
    for (int i =0; i < numRows; i++) {
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
