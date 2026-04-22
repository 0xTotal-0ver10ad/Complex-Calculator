#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
private:
    double re;
    double im;

public:
    Complex();
    Complex(double r, double i);

    Complex add(const Complex& rhs) const;
    Complex sub(const Complex& rhs) const;
    Complex mul(const Complex& rhs) const;
    Complex div(const Complex& rhs) const;

    double magnitude() const;

    double getReal() const;
    double getImag() const;
};

#endif