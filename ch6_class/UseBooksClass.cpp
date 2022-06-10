#include <iostream>
#include "Books.hpp"

int main(int argc, char* argv[]) {
    Books good_read;
    good_read.author = "C S Lewis";
    good_read.title = "The silver chair";
    good_read.publisher = "Geoffrey Bles";
    good_read.price = 699;
    good_read.format = "paperback";
    good_read.SetYearOfPublication(1953);

    Books another_book(good_read);
    Book an_extra_book("The Magician's nephew");

    // Demonstrate pointer to class
    Books* p_book_i_am_reading = new Book;
    (*p_book_i_am_reading).author = "Philip Pullman";
    // Below is more convenient way to accessing a class member
    // associated with a pointer to a class in which the forward arrow
    // ->, means "de-reference" and then access the member
    p_book_i_am_reading->title = "Lyra's Oxford";

    delete p_book_iread; // to always write a delete statement
                         // to match a new statement
    return 0;
}
// int main(int argc, char* argv[]) {
//     // demonstrates how to use the overridden default constructor
//     Books my_book;
//     std::cout << "The author is " << my_book.author << "\n";
//     // The code above will print “The author is unspecified”.
//     Books promotion_book;
//     promotion_book.author = "Iris Murdoch";
//     promotion_book.title = "The sea, the sea";
//     promotion_book.publisher = "Chatto & Windus";
//     promotion_book.price = 299;
//     promotion_book.format = "hardback";
//     promotion_book.SetYearOfPublication(1978);

//     std::cout << "Year of publiction of "
//               << promotion_book.title << " is "
//               << promotion_book.GetYearOfPublication()
//               << "\n";
// }

// How to compile multiple files
// g++ -Wall -O -c Books.cpp
// g++ -Wall -O -c UseBooksClass.cpp
// g++ -Wall -lm -O -o UseBooksClass UseBooksClass.o Books.o

// Or: it is possible to skip one step in the compilation process so that 
// we do not have to explicitly produce the intermediate file UseBookClass.o.

// g++ -Wall -O -c Books.cpp
// g++ -Wall -lm -O -o UseBooksClass UseBooksClass.cpp Books.o

// ./UseBooksClass
