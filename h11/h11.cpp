/**
    @file h11.cpp
    @author Aliyan Ismail
    @version Spring 21 WPM
*/
#include <string>
#include <stdexcept>
using namespace std;

#include "h11.h"

string STUDENT = "aismail9"; // Add your Canvas/occ-email ID

// Add your function implementations here
bool find(const string& s, const string& t)
{
    auto tlen = t.length();
    auto slen = s.length();
    if (slen < tlen || (slen == tlen && s != t)) {return false;}
    else if (s.substr(0, tlen) == t) {return true;}
    else {return find(s.substr(1), t);}
}

string stringClean(const string& str)
{
    if (str.length() == 0) {return "";}
    if (str.length() == 1) {return str;}
    if (str.at(0) == str.at(1)) {return stringClean(str.substr(1));}
    else {return str.at(0) + stringClean(str.substr(1));}
}

////////////////// Student Testing //////////////////////////
#include <iostream>
int run()
{
    cout << "Student testing" << endl;
    return 0;
}

