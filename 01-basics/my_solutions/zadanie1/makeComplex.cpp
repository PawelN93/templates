#include <iostream>
#include <complex>
#include "makeComplexTemplate.hpp"

int main(){

    auto z1 = makeComlex(7.3, 5);

    std::cout << "Real part: " << z1.real() << "\tImag part: " << z1.imag() << std::endl;


    return 0;
}