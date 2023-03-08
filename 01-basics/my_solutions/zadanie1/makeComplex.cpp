// Zadanie
// Napisz funkcję makeComplex(), która tworzy liczbę zespoloną std::complex z dwóch dostarczonych liczb. Jeśli typy tych liczb są różne, powinna utworzyć się liczba zespolona z typem pierwszego parametru.

// std::complex<int> a = makeComplex(4, 5);        // both ints
// std::complex<double> b = makeComplex(3.0, 2.0); // both doubles
// std::complex<int> c = makeComplex(1, 5.0); // int, double -> takes int

#include <iostream>
#include <complex>
#include "makeComplexTemplate.hpp"

int main(){

    auto z1 = makeComlex(7.3, 5);

    std::cout << "Real part: " << z1.real() << "\tImag part: " << z1.imag() << std::endl;


    return 0;
}