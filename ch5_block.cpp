#include <iostream> 
// use g++ -Wshadow -o ch5 .\ch5_function.cpp to compile this code could see shadow variable warning
int i = 5; // global i

int main(int argc, char** argv) {
    int j = 7;
    std::cout << i << "\n";
    {
        int i = 10, j = 11;
        std::cout << i << "\n"; // local value of i is 10
        std::cout << ::i << "\n"; // global value of i is 5
        std::cout << j << "\n"; // value of j here is 11
        //The other j (value 7) is inaccessible
    }
    std::cout << j << "\n"; // value of j here is 7
    return 0;
}