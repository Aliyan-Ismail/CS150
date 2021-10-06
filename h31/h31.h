/**
    @file h31.h
    @author Stephen Gilbert
    @version Spring 2021
*/
#ifndef H31_H_
#define H31_H_
#include <iostream>
#include <string>

class Fraction
{
public:
    Fraction() = default;
    Fraction(int n);
    Fraction(int n, int d);

    Fraction& operator+=(const Fraction& rhs);
    Fraction& operator-=(const Fraction& rhs);
    Fraction& operator*=(const Fraction& rhs);
    Fraction& operator/=(const Fraction& rhs);

    std::string toString() const;

private:
    int m_numerator = 0;
    int m_denominator = 1;
};

std::ostream& operator<<(std::ostream& out, const Fraction& f);

const Fraction operator+(const Fraction& lhs, const Fraction& rhs);
const Fraction operator-(const Fraction& lhs, const Fraction& rhs);
const Fraction operator*(const Fraction& lhs, const Fraction& rhs);
const Fraction operator/(const Fraction& lhs, const Fraction& rhs);

#endif
