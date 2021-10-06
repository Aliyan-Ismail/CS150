/**
 *  @author Aliyan Ismail
 *  @date Spring 21 WPM
 *  @file h25.cpp
 */
#include <string>
#include <iostream>
using namespace std;

string STUDENT = "aismail9"; // Add your Canvas/occ-email ID

#include "h25.h"

// Add your code here
/**
 * Reverses the C-style string pointed to by s.
 *
 * @param s a pointer to the character in a C-style string.
 */
void reverse(char * s)
{
    auto * begin = s;
    auto * end = s;
    while (*end != '\0') {end++;}
    end--;
    while (begin < end)
    {
        auto temp = *begin;
        *begin = *end;
        *end = temp;
        begin++;
        end--;
    }
}

/**
 * Finds the first occurrence of str2 which appears in str1.
 * Returns a pointer to the first occurrence of str2 in str1.
 * If no match is found, then a null pointer is returned.
 * If str2 points to a string of zero length, then the argument str1 is returned.
 *
 * @param str1 C-string to search through.
 * @param str2 C-string to search for.
 * @return
 */
const char * findStr(const char *str1, const char *str2)
{
    if (*str2 == '\0') {return str1;}
    while (*str1)
    {
        const char * p1 = str1;
        const char * p2 = str2;
        bool found = true;
        while (*p1 && *p2)
        {
            if (*p1 != *p2) {found = false; break;}
            p1++;
            p2++;
        }
        if (found) {return str1;}
        str1++;
    }
    return nullptr;
}




//////////////////////// STUDENT TESTING //////////////////////////

int run()
{
    cout << "Add your own tests here" << endl;
    return 0;
}