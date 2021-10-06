/**
 *  @author Aliyan Ismail
 *  @date Spring 21 WPM
 *  @file h09.cpp
 */
#include <string>
#include <iostream>
using namespace std;

string STUDENT = "aismail9"; // Add your Canvas/occ-email ID

#include "h08.h"

// Put your function implementation (definitions) in this file
string barCode(int zip)
{
    string result;
    int digit{0};
    int check = checkDigit(zip);
    string checkCode = codeForDigit(check);
    string code;
    string frameBar = "|";
    
    for (size_t i = 0; i < 5; ++i)
    {
        digit = zip % 10;
        zip /= 10;
        code = codeForDigit(digit);
        result = code + result;
    }
    result += checkCode;
    result = frameBar + result + frameBar;
    
    return result;
}

string codeForDigit(int digit)
{
    string result;
    switch (digit)
    {
        case 1: result = ":::||"; break;
        case 2: result = "::|:|"; break;
        case 3: result = "::||:"; break;
        case 4: result = ":|::|"; break;
        case 5: result = ":|:|:"; break;
        case 6: result = ":||::"; break;
        case 7: result = "|:::|"; break;
        case 8: result = "|::|:"; break;
        case 9: result = "|:|::"; break;
        case 0: result = "||:::"; break;
    }
    return result;
}

int checkDigit(int zip)
{
    int result{0};
    size_t len = 5;
    int extra{0};
    int sum{0};
    for (size_t i = 0; i < len; ++i)
    {
        extra = zip % 10;
        zip /= 10;
        sum += extra;
    }
    if (sum % 10 > 0)
    {
        result = (10 - (sum % 10));
    }
    else {
        result = 0;
    }
    return result;
}




/////////// Student Testing ///////////////////////
#include <iostream>
int run()
{
    // You can add code that "runs" here
    return 0;
}