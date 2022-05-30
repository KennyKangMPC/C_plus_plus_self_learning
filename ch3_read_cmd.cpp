#include <iostream>
#include <cstdlib> // needed for using atoi/atof
#include <fstream>

int main(int argc, char *argv[]) {
    std::cout << "Number of command line arguments = "
              << argc << "\n";
    
    for (int i=0; i<argc; i++) {
        std::cout << "Argument " << i << " = " << argv[i];
        std::cout << "\n";
    }

    std::string program_name = argv[0];
    int number_of_nodes = atoi(argv[1]);
    double conductivity = atof(argv[2]);

    std::cout << "Program name = " << program_name << "\n";
    std::cout << "Number of nodes = " << number_of_nodes;
    std::cout << "\n";
    std::cout << "Conductivity = " << conductivity << "\n";

    std::ofstream write_file("OutputFormatted.dat");
    // Write numbers as +x.<13digits>e+00 (width 20)
    write_file.setf(std::ios::scientific);
    write_file.setf(std::ios::showpos); // always show plus and minus sign
    write_file.precision(13);

    double x = 3.4, y = 0.0000855, z = 984.424;
    write_file << x << " " << y << " " << z << "\n";
    write_file.close();
    return 0;
}
