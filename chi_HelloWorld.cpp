#include <iostream>

int main(int argc, char* argv[])
{
    /* This is a comment and will be ignored by the compiler
    Comments are useful to explain in English what the program does
    */
   // Print "Hello World" to the screen
   std::cout << "Hello World\n";
   return 0;
}

// g++ -O -o HelloWorld HelloWorld.cpp: the executable file should execute more quickly although compilation may take longer
// g++ -g -o HelloWorld HelloWorld.cpp: show specfic line 
// g++ -Wall -Werror -o HelloWorld HelloWorld.cpp: warn all no executable turn out to be error
// g++ -Wall -o HelloWorld HelloWorld.cpp: warn all but still produce executable
// g++ -lm -o HelloWorld HelloWorld.cpp: Allows us to link to a library of mathematical routines
// g++ -DNDEBUG program.cpp: they can be automatically removed when the code is compiled with the "DNDEBUG" flag.

// g++ -std=c++11 -o Unique Unique.cpp // this is used for unique or share_ponter
// We may use as many variables as we wish when compiling by simplying listing them one after the otehr when compiling the code

// -Wshadow // this is a flag that can be used to turing on "shadow warnings" in your computer
            // to avoird multiple declaration of variables known as "variable shadowing"

