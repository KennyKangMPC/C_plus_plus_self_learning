#ifndef BOOKSHEADERDEF
#define BOOKSHEADERDEF

#include <string>

class Books {
    public:
        std::string author, title, publisher, format;
        int price; //Given in pence
        void SetYearOfPublication(int year);
        int GetYearOfPublication() const;
        /* The keyword const after the declaration of this method is a signal to the compiler
            that we want to ensure that the instance of the class will remain constant throughout the execution of the method.
        */
    private:
        int mYearOfPublication;
}
#endif