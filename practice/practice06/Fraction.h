#pragma once
#include <iostream>
#include <stdexcept>

//AI used to help with friend functions

class Fraction {
private:
    int num;
    int den;

    void simplify();
public:
    //Constructors
    Fraction();
    Fraction(int n, int d);

    //Getters
    int getNumerator() const;
    int getDenominator() const;

    //Setters
    void setNumerator(int n);
    void setDenominator(int d);

    friend Fraction operator+(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator-(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator*(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator/(const Fraction& lhs, const Fraction& rhs);

    friend std::ostream& operator<<(std::ostream& os, const Fraction& frac);
};