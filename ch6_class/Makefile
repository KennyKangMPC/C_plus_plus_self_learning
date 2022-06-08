# The following is a Makefile for code
# UseClasses.cpp that uses two classes, Class1 and Class2.

# Class1.o : Class1.cpp Class1.hpp
# 		g++ -c -O Class1.cpp

# Class2.o : Class2.cpp Class2.hpp
# 		g++ -c -O class2.cpp

# UseClasses.o : UseClasses.cpp Class1.hpp Class2.hpp
# 		g++ -c -O UseClasses.cpp

# UseClasses : Class1.o Class2.o UseClasses.o
# 		g++ -O -o UseClasses Class1.o Class2.o UseClasses.o

# If the file above is saved as Makefile, then to generate an up-to-date executable
# file UseClasses we simply type “make UseClasses” at the command line.


Books.o : Books.cpp Books.hpp
	g++ -c -O Books.cpp

UseBooksClass.o : UseBooksClass.cpp Books.hpp
	g++ -c -O UseBooksClass.cpp

UseBooksClass : Books.o UseBooksClass.o
	g++ -O -o UseBooksClass Books.o UseBooksClass.o