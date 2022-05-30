// Newton-Raphson

#include <cmath>
#include <iostream>

void CalculateCubeRoot(double& x, double K, double tolerance = 1.0e-6, int maxIterations = 100);

int main(int argc, char* argv[]) {
    double x = 1.0;
    double K = 12.0;

    // Calculate cube root using default values
    CalculateCubeRoot(x, K);

    // Calculate cube root using a tolerance of 0.001 and the
    // default aximum number of iterations
    double tolerance = 0.001;
    x = 1.0; // Restart guess
    CalculateCubeRoot(x, K, tolerance);

    // Calculate cube root using a tolerance of 0.001 and a
    // maximum number of iterations of 50
    int maxIterations = 50;
    x = 1.0; // Restart guess
    CalculateCubeRoot(x, K, tolerance, maxIterations);
    return 0;
}

void CalculateCubeRoot(double& x, double K, double tolerance, int maxIterations) {
    int iterations = 0;
    double residual = x*x*x - K;
    std::cout << x << "\n";
    while ((fabs(residual) > tolerance) && (iterations < maxIterations)) {
        x = x-(x*x*x-K)/(3.0*x*x);
        residual = x*x*x-K;
        iterations++;
        std::cout << x << "\n";
    }
}