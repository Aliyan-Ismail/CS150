/**
 *  @file h31.cpp
 *  @author Aliyan Ismail
 *  @version Spring 21 WPM
 */
#include <string>
#include <stdexcept>
#include <cmath>
#include <iostream>
#include <sstream>
using namespace std;

string STUDENT = "aismail9"; // Add your Canvas/occ-email ID

#include "h31.h"

// Implement your class members here
static int gcd(int x, int y)
{
    int r = x % y;
    while (r != 0)
    {
        x = y;
        y = r;
        r = x % y;
    }
    return y;
}

/**
 * Check to see if denominator is zero, if so throw invalid argument
 * If the numerator is zero, set the denominator to 1
 * Else find the gcd using the function
**/

Fraction::Fraction(int n, int d)
{
    if (d == 0) {throw invalid_argument("Divison by zero error");}
    if (n == 0) {m_numerator = 0; m_denominator = 1;}
    else
    {
        int g = gcd(abs(n), abs(d));
        m_numerator = n / g;
        m_denominator = abs(d) / g;
        if (d < 0) {m_numerator = m_numerator * -1;}
    }
}

/**
 * Use the working constructor to create the default constructor as a delegating constructor
**/

Fraction::Fraction(int n) : Fraction(n, 1) {}

/**
 * Create 4 variables: a, b, c, d
 * Initialize a with the numerator, b with the denominator
 * Initialize c with the rhs numerator and d with the rhs denominator
 * Use the formulas from the pdf instructions to form the new Fraction
 * Return the fraction in the form of *this
**/

Fraction& Fraction::operator+=(const Fraction& rhs)
{
    int a = m_numerator;
    int b = m_denominator;
    int c = rhs.m_numerator;
    int d = rhs.m_denominator;
    *this = Fraction(a * d + b * c, b * d);
    return *this;
}

/**
 * Create 4 variables: a, b, c, d
 * Initialize a with the numerator, b with the denominator
 * Initialize c with the rhs numerator and d with the rhs denominator
 * Use the formulas from the pdf instructions to form the new Fraction
 * Return the fraction in the form of *this
**/

Fraction& Fraction::operator-=(const Fraction& rhs)
{
    int a = m_numerator;
    int b = m_denominator;
    int c = rhs.m_numerator;
    int d = rhs.m_denominator;
    *this = Fraction(a * d - b * c, b * d);
    return *this;
}

/**
 * Create 4 variables: a, b, c, d
 * Initialize a with the numerator, b with the denominator
 * Initialize c with the rhs numerator and d with the rhs denominator
 * Use the formulas from the pdf instructions to form the new Fraction
 * Return the fraction in the form of *this
**/

Fraction& Fraction::operator*=(const Fraction& rhs)
{
    int a = m_numerator;
    int b = m_denominator;
    int c = rhs.m_numerator;
    int d = rhs.m_denominator;
    *this = Fraction(a * c, b * d);
    return *this;
}

/**
 * Create 4 variables: a, b, c, d
 * Initialize a with the numerator, b with the denominator
 * Initialize c with the rhs numerator and d with the rhs denominator
 * Use the formulas from the pdf instructions to form the new Fraction
 * Return the fraction in the form of *this
**/

Fraction& Fraction::operator/=(const Fraction& rhs)
{
    int a = m_numerator;
    int b = m_denominator;
    int c = rhs.m_numerator;
    int d = rhs.m_denominator;
    *this = Fraction(a * d, b * c);
    return *this;
}

/**
 * Create an ostringstream out variable
 * Feed in the numerator
 * If the denominator is not 1, feed in the slash with the denominator
 * Return the out variable
**/

std::string Fraction::toString() const
{
    ostringstream out;
    out << m_numerator;
    if (m_denominator != 1) {out << "/" << m_denominator;}
    return out.str();
}

/**
 * Return out with calling the toString method
**/

std::ostream& operator<<(std::ostream& out, const Fraction& f)
{
    return out << f.toString();
}

/**
 * Create a result variable and initialize it with the lhs
 * Use the short hand operator to complete the operation
**/

const Fraction operator+(const Fraction& lhs, const Fraction& rhs)
{
    Fraction result{lhs};
    return result += rhs;
}

/**
 * Create a result variable and initialize it with the lhs
 * Use the short hand operator to complete the operation
**/

const Fraction operator-(const Fraction& lhs, const Fraction& rhs)
{
    Fraction result{lhs};
    return result -= rhs;
}

/**
 * Create a result variable and initialize it with the lhs
 * Use the short hand operator to complete the operation
**/

const Fraction operator*(const Fraction& lhs, const Fraction& rhs)
{
    Fraction result{lhs};
    return result *= rhs;
}

/**
 * Create a result variable and initialize it with the lhs
 * Use the short hand operator to complete the operation
**/

const Fraction operator/(const Fraction& lhs, const Fraction& rhs)
{
    Fraction result{lhs};
    return result /= rhs;
}

/////////////// STUDENT TESTING ////////////////////

int run()
{
    cout << "Uncomment these and use make run to test." << endl;
    // Fraction a(3, 6); // 1/2 after reducing
    // Fraction b(1, 3); // 1/3
    // Fraction c(1, 6); // 1/6

    // Fraction sum = a + b + c;

    // cout << a << " + " << b << " + " << c
    //     << " = " << sum << endl;

    return 0;
}

