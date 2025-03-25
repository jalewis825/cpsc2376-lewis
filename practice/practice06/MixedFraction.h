#pragma once

#include "Fraction.h"
#include <iostream>

class MixedFraction : public Fraction {
private:
    int whole; //whole number part of mixed fraction

public:
    //Constructors
    MixedFraction(int whole, int num, int den);
    MixedFraction(const Fraction& fraction); //convert fraction to mixed fraction

    friend std::ostream& operator<<(std::ostream& os, const MixedFraction& mixed);
};