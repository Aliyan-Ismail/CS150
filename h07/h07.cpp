/**
 *  @author Aliyan Ismail
 *  @date Spring 21 WPM
 *  @file h07.cpp
 */
#include <string>
#include <iostream>
using namespace std;

string STUDENT = "aismail9"; // Add your Canvas/occ-email ID

#include "h07.h"

// Place your function definitions in this file.
string zipZap(const string& str)
{
    int len = str.size();
    int i = 0;
    string result;
    if (len < 3)
    {
        result = str;
    }
    while (i < len && len >= 3)
    {
        string word = str.substr(i, 3);
        if (word.front() == 'z' && word.back() == 'p')
        {
            result += "zp";
            i += 3;
        }
        else {
            result += str.at(i);
            i++;
        }
    }
    return result;
}

int countCode(const string& str)
{
    int result = 0;
    size_t slen = 4;
    for (size_t i = slen, len = str.size(); i <= len; ++i)
    {
        string subs = str.substr(i - slen, slen);
        if (subs.substr(0, 2) == "co" && subs.back() == 'e')
        {
            result++;
        }
    }
    return result;
}

string everyNth(const string& str, int n)
{
    string result;
    size_t count = 0;
    if (n < 1)
    {
        result = "";
    }
    while (count < str.size())
    {
        result += str.at(count);
        count += n;
    }
    return result;
}

bool prefixAgain(const string& str, int n)
{
    string prefix = str.substr(0, n);
    bool result = false;
    for (size_t i = 1; i <= str.size(); ++i)
    {
        string word = str.substr(i, n);
        if (word == prefix)
        {
            result = true;
        }
    }
    return result;
}



////////////////// STUDENT TESTING /////////////
int run()
{
    cout << "Student testing" << endl;
    return 0;
}