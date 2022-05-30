#include <iostream>
#include <string> 
#include <cassert> // needed for using assert
#include <cmath>

int main(int argc, char* argv[])
{
    // std::string name;
    // std::cout << "Enter your name and then hit RETURN\n";
    // std::getline(std::cin, name);
    // std::cout << "Your name is " << name << "\n";

    double a;
    std::cout << "Enter a non-negative number\n";
    std::cin >> a;
    assert(a >= 0.0);
    assert(std::isfinite(a));
    assert(std::isinf(a));
    assert(std::isnan(a));
    std::cout << "The square root of " << a;
    std::cout << " is " << sqrt(a) << "\n";
    return 0;
}