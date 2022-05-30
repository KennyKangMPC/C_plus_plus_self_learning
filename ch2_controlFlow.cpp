/* Logical condition    Operator
        AND               &&
        OR                ||
        NOT               !
*/
#include <iostream>
#include <string> 
#include <cassert> // needed for using assert
#include <cmath>

int main(int argc, char* argv[]) {
    double vector1[2], vector2[2];
    vector1[0] = 0.5; vector1[1] = -2.3;
    vector2[0] = 34.2; vector2[1] = 0.015;

    double scalar_product = 0.0;
    for (int i = 0; i < 2; i++) {
        scalar_product += vector1[i] * vector2[i];
    }
}