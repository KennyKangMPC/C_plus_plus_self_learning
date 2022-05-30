#include <cassert>
#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
    double x[3] = {0.0, 1.0, 0.0};
    double y[3] = {0.0, 0.0, 1.0};
    std::ofstream write_output("Output.dat"); // will delete previous same-named files
    // if we don't want to delete, use:
    // std::ofstream write_output("Output.dat", std::ios::app);
    assert(write_output.is_open());

    for (int i=0; i<3; i++) {
        write_output << x[i] << " " << y[i] << "\n";
    }

    // set precision
    double x =  1.8364238;
    std::ofstream write_output("Output.dat", std::ios::app);

    write_output.precision(3); // 3 sig figs
    write_output << x << "\n";

    write_output.precision(5); // 5 sig figs
    write_output << x << "\n";

    write_output.precision(10); // 10 sig figs
    write_output << x << "\n";

    write_output.close();
    // write_output.flush();
    return 0;
}