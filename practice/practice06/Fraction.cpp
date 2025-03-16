#include "Fraction.h"

//AI used to help with the simplify function

//Default constructor
Fraction::Fraction() : num(0), den(1) {}

//Parameterized constructor
Fraction::Fraction(int n, int d) : num(n), den(d){
    if (d==0) throw std::invalid_argument("Denominator cannot be zero.");
    simplify();
}

//Getters
int Fraction::getNumerator() const {
    return num;
}

int Fraction::getDenominator() const {
    return den;
}


//Setters
void Fraction::setNumerator(int n){
    num = n;
    simplify();
}

void Fraction::setDenominator(int d) {
    if (d == 0) throw std::invalid_argument("Denominator cannot be zero.");
    den = d;
    simplify();
}

void Fraction::simplify() {
    if (den == 0) throw std::invalid_argument("Denominator cannot be zero.");

    int a = abs(num), b = abs(den);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    int gcd = a;
    num /= gcd;
    den /= gcd;

    // Make sure denominator is always positive
    if (den < 0) {
        num = -num;
        den = -den;
    }
}