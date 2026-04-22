#include "Complex.h"
#include <cmath>

Complex::Complex() : re(0.0), im(0.0) {}

Complex::Complex(double r, double i) : re(r), im(i) {}

Complex Complex::add(const Complex& rhs) const {
    return Complex(re + rhs.re, im + rhs.im);
}

Complex Complex::sub(const Complex& rhs) const {
    return Complex(re - rhs.re, im - rhs.im);
}

Complex Complex::mul(const Complex& rhs) const {
    return Complex(
        re * rhs.re - im * rhs.im,
        re * rhs.im + im * rhs.re
    );
}

Complex Complex::div(const Complex& rhs) const {
    double den = rhs.re * rhs.re + rhs.im * rhs.im;
    if (den == 0.0)
        throw 1;

    return Complex(
        (re * rhs.re + im * rhs.im) / den,
        (im * rhs.re - re * rhs.im) / den
    );
}

double Complex::magnitude() const {
    return std::sqrt(re * re + im * im);
}

double Complex::getReal() const {
    return re;
}

double Complex::getImag() const {
    return im;
}