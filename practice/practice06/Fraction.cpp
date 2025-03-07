#include "Fraction.h"
#include <stdexcept>

class Fraction {
private:
    int numerator;
    int denominator;

public:

    Fraction(int num, int denom) : numerator(num), denominator(denom){
        if (denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
    }
}
void Fraction::simplify() {
    if (den == 0) throw std::invalid_argument("Denominator cannot be zero");
 
    // Compute GCD using Euclidean algorithm
    int a = num, b = den;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    int gcd = a; // GCD is stored in 'a' after loop exits
 
    // Simplify the fraction
    num /= gcd;
    den /= gcd;
}