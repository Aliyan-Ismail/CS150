/**
    @file h33.cpp
    @author Aliyan Ismail
    @version Spring 21 WPM
*/
#include <string>
#include <stdexcept>
#include <sstream>
#include <iomanip>
using namespace std;

string STUDENT = "aismail9"; // Add your Canvas/occ-email ID

#include "h33.h"
///////// Add your code here ///////////////

Circle::Circle(double r, double x, double y)
    : Point(x, y), radius(r) {}

double Circle::getRadius() const { return radius; }

double Circle::getArea() const
{
    return PI * radius * radius;

}
double Circle::getCircumference() const
{
    return 2 * PI * radius;

}
string Circle::toString(int decimals) const
{
    ostringstream out;
    out << fixed << setprecision(decimals);
    out << "Circle(radius=" << radius << ", center="
        << Point::toString(decimals) << ")";
    return out.str();
};

Cylinder::Cylinder(double h, double r, double x, double y)
    : Circle(r, x, y), height(h) {}

double Cylinder::getHeight() const { return height; }

double Cylinder::getVolume() const
{
    return PI * getRadius() * getRadius() * height;
}

double Cylinder::getArea() const
{
    return 2 * Circle::getArea() + 2 * PI * getRadius() * height;
}

string Cylinder::toString(int decimals) const
{
    ostringstream out;
    out << fixed << setprecision(decimals);
    out << "Cylinder(height=" << height
        << ", base=" << Circle::toString(decimals) << ")";
    return out.str();
};

//////////////// Student Tests ////////////////////////////
#include <iostream>
int run()
{
    cout << "Student testing" << endl;
    return 0;
}
