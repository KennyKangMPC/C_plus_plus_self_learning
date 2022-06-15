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

ComplexNumber.o : ComplexNumber.cpp ComplexNumber.hpp
	g++ -c -O ComplexNumber.cpp

useComplex.o : UseComplex.cpp ComplexNumber.hpp
	g++ -c -O UseComplex.cpp

useComplex : ComplexNumber.o useComplex.o
	g++ -O -o useComplex ComplexNumber.o useComplex.o