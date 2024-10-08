#ifndef RATIONAL_H_
#define RATIONAL_H_

#include <iostream>

using namespace std;

class Rational {
    public:
        // Constructors
        Rational();
        Rational(int top, int bottom);

        // Getters
        int getTop() const;
        int getBottom() const;

        // Setters
        bool setValue(int top, int bottom);

        // Functions
        Rational Multiply(Rational& rat) const;
        Rational Divide(Rational& rat) const;
        Rational Add(Rational& rat) const;
        Rational Subtract(Rational& rat) const;

    private:
        // Values
        int top_;
        int bottom_;
        
        // Functions
        void reduce();

};

#endif