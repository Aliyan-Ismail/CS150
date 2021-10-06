/**
 *  @author Aliyan Ismail
 *  @date Spring 21 WPM
 *  @file h12.cpp
 */
#include <string>
#include <iostream>
using namespace std;

string STUDENT = "aismail9"; // Add your Canvas/occ-email ID

// Write your function here
void strip()
{
    char c;
    bool inSingle = false;
    bool inMulti = false;
    bool inStr = false;
    while (cin.get(c))
    {
        if (inSingle && c == '\n') {inSingle = false;}
        else if (inStr && c == '\\' && cin.peek() == '"')
        {
            cout.put(c);
            cin.get(c);
        }
        else if (inStr && c == '"') {inStr = false;}
        else if (inMulti && c == '*' && cin.peek() == '/')
        {
            inMulti = false;
            cin.get(c);
            cin.get(c);
        }
        else if (!inStr && !inSingle && !inMulti)
        {
            if (c == '"') {inStr = true;}
            else if (c == '/' && cin.peek() == '*') {inMulti = true;}
            else if (c == '/' && cin.peek() == '/') {inSingle = true;}
        }
        if (cin && !inSingle && !inMulti) {cout << c;}
    }
}

//////////////// STUDENT TESTING ////////////////////
int run()
{
    //cout << "Student testing" << endl;
    strip();
    return 0;
}