#include <complex>

template <typename T, typename U>
std::complex<T> makeComlex(T a, U b){
    return std::complex<T>{a, static_cast<T>(b)};
}