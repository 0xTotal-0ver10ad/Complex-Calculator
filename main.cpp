#include <iostream>
#include <string>
#include <iomanip>
#include "Complex.h"

bool parseComplex(const std::string& str, Complex& val) {
    if (str.back() != 'i') return false;

    size_t idx = std::string::npos;
    for (size_t i = 1; i < str.size() - 1; ++i) {
        if (str[i] == '+' || str[i] == '-') {
            idx = i;
            break;
        }
    }
    if (idx == std::string::npos) return false;

    try {
        double r = std::stod(str.substr(0, idx));
        double i = std::stod(str.substr(idx, str.size() - idx - 1));
        val = Complex(r, i);
        return true;
    } catch (...) {
        return false;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "ERROR: Invalid arguments";
        return 0;
    }

    std::string cmd = argv[1];

    if (cmd == "magnitude") {
        if (argc != 3) {
            std::cout << "ERROR: Invalid arguments";
            return 0;
        }

        Complex z;
        if (!parseComplex(argv[2], z)) {
            std::cout << "ERROR: Invalid complex number";
            return 0;
        }

        std::cout << std::fixed << std::setprecision(6)
                  << z.magnitude();
        return 0;
    }

    if (argc != 4) {
        std::cout << "ERROR: Invalid arguments";
        return 0;
    }

    Complex z1, z2;
    if (!parseComplex(argv[2], z1) || !parseComplex(argv[3], z2)) {
        std::cout << "ERROR: Invalid complex number";
        return 0;
    }

    try {
        Complex res;

        if (cmd == "add") res = z1.add(z2);
        else if (cmd == "sub") res = z1.sub(z2);
        else if (cmd == "mul") res = z1.mul(z2);
        else if (cmd == "div") res = z1.div(z2);
        else {
            std::cout << "ERROR: Unknown operation";
            return 0;
        }

        std::cout << std::fixed << std::setprecision(6)
                  << res.getReal();

        if (res.getImag() >= 0)
            std::cout << "+";

        std::cout << res.getImag() << "i";

    } catch (...) {
        std::cout << "ERROR: Division by zero";
    }

    return 0;
}