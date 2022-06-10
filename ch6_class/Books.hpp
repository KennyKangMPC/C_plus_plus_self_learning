#ifndef BOOKSHEADERDEF
#define BOOKSHEADERDEF

#include <string>
#include <cassert>

// access privileges is stored in this kind of header file

// When working on large projects that requre the use of multiple
// classes it can be difficult to keep track of the class
// members and their access privileges (stored in the header file)
// and the implementations of the member functions (stored in the .cpp file)
// Therefore, if functions associated with a class require only a few
// lines of code then it may be more convenient to include the implementation
// of these functions in the header file.
class Books {
    public:
        /*
        Note that when overriding the default constructor this function
        has the same name as the class, takes no arguments, has no return type and must be
        a public member of the class.
        */
        Books();
        /*
        Note that the argument to a copy constructor has to be
        a reference to another instance of the class, rather than that object itself. This is
        because, by default, all method arguments are called by copy. 
        */

        Books(const Books& otherBook);
        Books(std::string bookTitle);
        std::string author, title, publisher, format;
        int price; //Given in pence
        // void SetYearOfPublication(int year) {
        //     assert ((year > 1440) && (year < 2020));
        //     mYearOfPublication = year;
        // }
        // int GetYearOfPublication() const {
        // /* The keyword const after the declaration of this method is a signal to the compiler
        //     that we want to ensure that the instance of the class will remain constant throughout the execution of the method.
        // */
        //     return mYearOfPublication;
        // }
        void SetYearOfPublication(int year);
        int GetYearOfPublication() const;

    private:
        int mYearOfPublication;
};
#endif