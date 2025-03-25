//AI used to help me write the function for the converting to mixed fraction and overloading << operator

#include "MixedFraction.h"
#include <stdexcept>

//Constructor that takes whole number, numerator, and denominator
MixedFraction::MixedFraction(int whole, int num, int den) : Fraction(num, den), whole(whole) {
    if (den == 0) throw std::invalid_argument("Denominator cannot be zero.");
}

//Constructor that converts improper fraction to Mixed Fraction
MixedFraction::MixedFraction(const Fraction& fraction) : Fraction(fraction) {
    whole = fraction.getNumerator() / fraction.getDenominator();
    int remainder = abs(fraction.getNumerator()) % fraction.getDenominator();

    if (fraction.getNumerator() < 0 && remainder != 0) {
        whole = -abs(whole);
    }
    setNumerator(remainder); //updates the fraction part
}

std::ostream& operator<<(std::ostream& os, const MixedFraction& mixed) {
    if (mixed.whole != 0) {
        os << mixed.whole;
        if (mixed.getNumerator() != 0) os << " " << mixed.getNumerator() << "/" << mixed.getDenominator();
    }
    else {
        os << mixed.getNumerator() << "/" << mixed.getDenominator();
    }
    return os;
}