/**
 *  @author Aliyan Ismail
 *  @date Spring 21 WPM
 *  @file h10.cpp
 */
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

string STUDENT = "aismail9"; // Add your Canvas/occ-email ID

#include "h10.h"

// Place your function definitions in this file.

bool read(const string& s, int& age, bool result)
{
    cin >> age;
    cout << s;
    if (cin.fail()) {return false;}
    else {return true;}
}

bool read(const string& s, string& name, bool result)
{
    cout << s;
    if (result) {getline(cin, name);}
    else {cin >> name;}

    return result;
}

bool read(const string& s, double& gpa, bool result)
{
    cin >> gpa;
    cout << s;
    if (cin.fail()) {return false;}
    else {cin >> gpa;}
    return result;
}

bool read(char& a, char c)
{
    cin.get(a);
    if (a == c) {return false;}
    else {return true;}
}



////////////////// STUDENT TESTING /////////////
int run()
{
    cout << "Student testing" << endl;

    // int age;
    // if (read("How old are you? ", age))
    //     cout << "You don't look " << age << " years old!" << endl;
    // else
    //     cout << "Hmm. Doesn't look like you entered an int." << endl;

    // double gpa;
    // if (read("What is your gpa? ", gpa, true))
    //     cout << "Wow! " << fixed << setprecision(2) << gpa << "? I'm impressed." << endl;
    // else
    //     cout << "Sorry. I can't understand what you typed." << endl;

    // string name;
    // if (read("What is your full name? ", name, true))
    //     cout << "Hi " << name << ". Glad to meet you." << endl;
    // else
    //     cout << "Hmm. Is that your FULL name?" << endl;

    // cout << "Type a sentence ending in a period: ";
    // char ch;
    // while (read(ch, '.')) cout << ch;
    // cout << "." << endl;

    return 0;
}

