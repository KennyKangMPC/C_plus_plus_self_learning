#include <iostream>
#include "Books.hpp"

int main(int argc, char* argv[]) {
    Books promotion_book;
    promotion_book.author = "Iris Murdoch";
    promotion_book.title = "The sea, the sea";
    promotion_book.publisher = "Chatto & Windus";
    promotion_book.price = 299;
    promotion_book.format = "hardback";
    promotion_book.SetYearOfPublication(1978);

    std::cout << "Year of publiction of "
              << promotion_book.title << " is "
              << promotion_book.GetYearOfPublication()
              << "\n";
}

// How to compile multiple files
// g++ -Wall -O -c Books.cpp
// g++ -Wall -O -c UseBooksClass.cpp
// g++ -Wall -lm -O -o UseBooksClass UseBooksClass.o Books.o

// Or: it is possible to skip one step in the compilation process so that 
// we do not have to explicitly produce the intermediate file UseBookClass.o.

// g++ -Wall -O -c Books.cpp
// g++ -Wall -lm -O -o UseBooksClass UseBooksClass.cpp Books.o

// ./UseBooksClass
