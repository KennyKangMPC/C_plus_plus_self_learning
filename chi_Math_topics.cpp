#include <cmath> // for some functions for doing math
#include <iostream> // for input and output
#include <string> // for string

int main(int argc, char* argv[])
{
    double x = 1.0, y = 2.0, z;
    z = x/y;        // division
    z = x*y;
    z = sqrt(x);
    z = exp(y);
    z = pow(x, y);  // x to the power of y
    z = M_PI;       // z stores the value of pi

    return 0;
    // others like cos, sin. tan, acos, asin, atan, cosh, sinh, tanh, log, log10, ceil, floor 
    // can be used in exactly the same way as sqrt and exp in the code above

    int i = 5, j = 2;
    double k;
    k = ((double) (i)) / ((double)(j)); // explicit type conversion
    std::cout << k << "\n";

    // Array
    int array1[2];
    double array2[2][3];

    array1[0] = 1;
    array1[1] = 10;
    array2[0][0] = 6.4;
    array2[0][1] = -3.1;
    array2[0][2] = 55.0;
    array2[1][0] = 63.0;
    array2[1][1] = -100.9;
    array2[1][2] = 50.8;

    array1[0]++;
    array2[1][2] = array2[0][1] + array2[1][0];

    double array3[3] = {5.0, 1.0, 2.0};
    int array4[2][3] = { {1, 1, 1}, {2, 2 ,2}}

    bool flag1, flag2;
    flag1 = true;
    flag2 = false;

    char letter;
    letter = 'a'; // note the single quotation marks

    std::cout << "The character is " << letter << "\n";

    //string book:
    std::string city; //note the std::
    city = "Oxford";  // note the double quotation marks
    std::cout << "String length = " << city.length() << "\n";
    std::cout << "Third character =" << city.at(2) << "\n";
    std::cout << "Third character =" << city[2] << "\n";
    std::cout << city << "\n"; //Prints the string in city
    std::cout << city.c_str() << "\n"; // Also prints city, but does so by first converting from a C++ string to a C string
                                       //, which is an array of type char. It is useful in cases where we need to pass a C++ string to a function
                                       // which expects an array of type char
    
    //Simple input and output
    std::cout.flush(); // immediate output is desirable

    int account_number, pin;
    std::cout << "Enter your account number\n";
    std::cout << "and then your PIN, then hit RETURN\n";
    std::cin >> account_number, pin;

    // while for string it is different lets see:
    std::string name;
    std::cout << "Enter your name and then hit RETURN\n";
    std::getline(std::cin, name);
    std::cout << "Your name is " << name << "\n";
    
    
    return 0;
}