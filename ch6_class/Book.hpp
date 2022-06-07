#include <string>
#ifndef EXAMPLECLASSSHEADERDEF              // only if macro
                                            // EXAMPLECLASSHEADERDEF not
                                            // defined execute lines of
                                            // code until #endif
                                            // statement
#define EXAMPLECLASSSHEADERDEF              // define the macro
                                            // EXAMPLECLASSHEADERDEF
                                            // Ensures that this code is
                                            // only compiled once, no
                                            // matter how many times it
                                            // is included

class Book { // body of header file
    public:
        std::string author, title, publisher, format;
        int price; // Given in Pence
        int yearOfPublication;
}; //Note that the class ends with ;

#endif // need one of these for every #ifndef statement