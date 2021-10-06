/**
    @file h34.cpp
    @author Aliyan Ismail
    @version Spring 21 WPM
*/
#include <string>
#include <stdexcept>
#include <iomanip>
#include <sstream>
using namespace std;

#include "h34.h"

string STUDENT = "aismail9"; // Add your Canvas/occ-email ID

// Add your implementation here
Worker::Worker(const std::string& name, double rate) : name(name), rate(rate) {}

double Worker::getRate() const {return rate;}

string Worker::getName() const {return name;}

SalariedWorker::SalariedWorker(const std::string& name, double rate) : Worker(name, rate) {}

string SalariedWorker::payInfo(int hours) const
{
    ostringstream out;
    out << fixed << setprecision(2);
    double result = 40 * getRate();
    out << getName() << "(Salaried, $ " << getRate() << ") worked " << hours << " hours. Pay: $ " << result;
    return out.str();
}

HourlyWorker::HourlyWorker(const std::string& name, double rate) : Worker(name, rate) {}

string HourlyWorker::payInfo(int hours) const
{
    ostringstream out;
    out << fixed << setprecision(2);
    double result;
    if (hours <= 40) {result = hours * getRate();}
    else {result = (40 * getRate()) + ((hours - 40) * (getRate() * 1.5));}
    out << getName() << "(Hourly, $ " << getRate() << ") worked " << hours << " hours. Pay: $ " << result;
    return out.str();
}

/////////////// Student Tests ////////////////////////////
#include <iostream>
int run()
{
	cout << "Student testing" << endl;
	return 0;
}
