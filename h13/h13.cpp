/**
 *  @author Put your name here
 *  @date Put the date here
 *  @file h13.cpp
 */
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

string STUDENT = "aismail9"; // Add your Canvas/occ-email ID

#include "h13.h"

// Implement your function here
string dataSets(const string& fname)
{
    string result;
    ifstream in(fname);
    
    if (in.fail())
    {
        return fname + " cannot be opened.";
    }
    ostringstream out;
    int dataSet = 1;
    int r;
    in >> r;
    while (!in.fail())
    {
        double sum = 0.0;
        double count = 0.0;
        while (r != 0)
        {
            double value;
            in >> value;
            count += r;
            sum += value * r;
            in >> r;
        }
        if (dataSet > 1)
        {
            out << endl;
        }
        out << "data set " << dataSet << ": total values = " << setprecision(0) << fixed << count << endl << "average value = " << setprecision(4) << fixed << (sum / count) << endl;
        dataSet++;
        in >> r;
    }
    result = out.str();
    return result;
}


///////////////// Student Testing /////////////////////////
int run()
{
    cout << "Student tests" << endl;
    return 0;
}