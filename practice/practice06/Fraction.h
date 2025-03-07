#pragma once


double MixedFraction(int whole, int n, int d); // Initializes a mixed fraction
double MixedFraction(const double Fraction& fraction); // Converts a fraction to mixed form
int getNumer() const;
int getDenom() const;
void setNumer(int n);
void setDenom(int d);//throw exception if d == 0 