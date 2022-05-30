#include <cmath>
#include <iostream>

// Function to calculate the p-norm of a vector:
// = [ Sum_i ( |x_i|**p)] **(1/p)
// See "An Introduction to Numerical Analysis" by
// Endre Suli and David Mayers, page 60, for definition
// of the p-norm of a vector
// x is a pointer to the vector which is of size vecSize
// Implementation of Newton-Raphson iterations
double CalculateNorm(double* x, int vecSize, int p) {
    double sum = 0.0;
    // Loop over elems x_i of x, incrementing sum by |x_i|**p
    for (int i = 0; i < vecSize; i++) {
        double temp = fabs(x[i]);
        sum += pow(temp, p);
    }
    // Return p-th root of sum
    return pow(sum, 1.0/p);
}

double SolveNewton(double (*pFunc)(double), double (*pFuncPrime)(double), double x) {
    double step;
    do {
        step = (*pFunc)(x) / (*pFuncPrime)(x);
        x -= step;
    } while (fabs(step) > 1.0e-5);
    return x;
}

// Function to calculate x that satisfies sqrt(x)=10
double Sqrt10(double x) {
    return sqrt(x) - 10.0;
}

// Derivative of function to calculate x that satisfies sqrt(x)=10
double Sqrt10Prime(double x) {
    return 1.0/(2.0*sqrt(x));
}

// Function to calculate x that satisfies x*x*x=10
double Cube10(double x) {
    return x*x*x - 10.0;
}

double Cube10Prime(double x) {
    return 3.0*x*x;
}

int main(int argc, char* argv[]){
    std::cout << "Root sqrt(x)=10, with guess 1.0 is "
              << SolveNewton(Sqrt10,Sqrt10Prime,1.0) << "\n";
    std::cout << "Root x**3=10, with guess 1.0 is "
              << SolveNewton(Cube10,Cube10Prime,1.0) << "\n";
    return 0;
}

