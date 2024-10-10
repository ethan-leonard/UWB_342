#include <iostream>
#include "Rational.h"

using namespace std;

// Constructors
Rational::Rational() : top_(0), bottom_(1) {}
Rational::Rational(int top, int bottom) : top_(top), bottom_(bottom) {
    if (bottom == 0) {
        top_ = 0;
        bottom_ = 1;
    }
    
}

// Getters
int Rational::getBottom() const {
    return bottom_;
}

int Rational::getTop() const {
    return top_;
}

// Setters 
bool Rational::setValue(int top, int bottom) {
    if (bottom == 0) {
        return false;
    } else {
        return true;
    }
}

// Functions

Rational Rational::operator*(const Rational& rat) const {
    Rational tmp;
    tmp.top_ = rat.top_ * top_;
    tmp.bottom_ = rat.bottom_ * bottom_;
    return tmp;
} 

Rational Rational::operator+(const Rational& rat) const {
    Rational tmp;
    tmp.top_ = (Rational::top_ * rat.bottom_) + (rat.top_ * Rational::bottom_);
    tmp.bottom_ = Rational::bottom_ * rat.bottom_;
    return tmp;
} 

