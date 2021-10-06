/**
 *  @author Aliyan Ismail
 *  @date Spring 21 WPM
 *  @file h09.cpp
 */
#include <string>
using namespace std;

string STUDENT = "aismail9"; // Add your Canvas/occ-email ID

#include "h09.h"

// Put your function implementation (definitions) in this file
string digit(int n, const string& symbols)
{
    string result;
    int ones{0};
    int tens{0};
    int hundreds{0};
    int thousands{0};
    if (symbols == "IVX")
    {
        switch (n)
        {
            case 1: result += "I"; break;
            case 2: result += "II"; break;
            case 3: result += "III"; break;
            case 4: result += "IV"; break;
            case 5: result += "V"; break;
            case 6: result += "VI"; break;
            case 7: result += "VII"; break;
            case 8: result += "VIII"; break;
            case 9: result += "IX"; break;
            case 10: result += "X"; break;
        }
    }
    else if (symbols == "XLC")
    {
        switch (n)
        {
            case 1: result += "X"; break;
            case 2: result += "XX"; break;
            case 3: result += "XXX"; break;
            case 4: result += "XL"; break;
            case 5: result += "L"; break;
            case 6: result += "LX"; break;
            case 7: result += "LXX"; break;
            case 8: result += "LXXX"; break;
            case 9: result += "XC"; break;
            case 10: result += "C"; break;
        }
    }
    else if (symbols == "CDM")
    {
        switch (n)
        {
            case 1: result += "C"; break;
            case 2: result += "CC"; break;
            case 3: result += "CCC"; break;
            case 4: result += "CD"; break;
            case 5: result += "D"; break;
            case 6: result += "DC"; break;
            case 7: result += "DCC"; break;
            case 8: result += "DCCC"; break;
            case 9: result += "CM"; break;
            case 10: result += "M"; break;
        }
    }
    else if (symbols == "M")
    {
        switch (n)
        {
            case 1: result += "M"; break;
            case 2: result += "MM"; break;
            case 3: result += "MMM"; break;
        }
    }
    return result;
}

string toRoman(int n)
{
    string result;
    int ones{0};
    int tens{0};
    int hundreds{0};
    int thousands{0};
    if (n <= 0 || n > 3999)
    {
        result = "OUT OF RANGE";
    }
    else {
        if (n < 10)
        {
            result = digit(n, "IVX");
        }
        else if (n >= 10 && n < 100)
        {
            ones = n % 10;
            tens = n / 10;
            result += digit(tens, "XLC");
            result += digit(ones, "IVX");
        }
        else if (n >= 100 && n < 1000)
        {
            ones = n % 10;
            tens = (n / 10) % 10;
            hundreds = n / 100;
            result += digit(hundreds, "CDM");
            result += digit(tens, "XLC");
            result += digit(ones, "IVX");
        }
        else if (n >= 1000 && n <= 3999)
        {
            ones = n % 10;
            tens = (n / 10) % 10;
            hundreds = (n / 100) % 10;
            thousands = n / 1000;
            result += digit(thousands, "M");
            result += digit(hundreds, "CDM");
            result += digit(tens, "XLC");
            result += digit(ones, "IVX");
        }
    }
    
    return result;
}





/////////// Student Testing ///////////////////////
int run()
{
    return 0;
}