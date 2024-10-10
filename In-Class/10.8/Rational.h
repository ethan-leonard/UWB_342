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

        // Operator overloads
        Rational operator*(const Rational& rat) const;
        Rational operator/(const Rational& rat) const;
        Rational operator+(const Rational& rat) const;
        Rational operator-(const Rational& rat) const;

        Rational& operator*=(const Rational& rat);

        // Friend function for output stream
        friend ostream& operator<<(ostream& os, const Rational& rat);
        

    private:
        // Values
        int top_;
        int bottom_;
        
        // Functions
        void reduce();

};

#endif