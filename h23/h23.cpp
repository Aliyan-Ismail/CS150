/**
 *  @author Aliyan Ismail
 *  @date Spring 21 WPM
 *  @file h23.cpp
 */
#include <string>
#include <iostream>
using namespace std;

string STUDENT = "aismail9"; // Add your Canvas/occ-email ID

#include "h23.h"

// Add your code here
/**
 *  Calculates an alternating sum of the elements in a.
 *  @param a an array of const int.
 *  @param size the number of elements in the array.
 *  @pre #size is > 0
 *  @return the alternating sum of {a, b, c, d} -> a - b + c - d
 *  Don't worry about overflow of the result.
 */
int alternatingSum(const int a[], size_t size)
{
    int result = 0;
    for (size_t i = 0; i < size; ++i)
    {
        if (i % 2 == 0) {result += a[i];}
        else {result -= a[i];}
    }
    return result;
}

/**
 * Returns pointers to the extreme values in the array.
 * @param a pointer the first element in an array of doubles
 * @param size the number of elements in the array.
 * @return a MinMax structure; nullptrs if size is 0.
 */
MinMax minMax(const double *ptr, size_t size)
{
    MinMax result;
    result.min = ptr;
    result.max = ptr;
    const double *atEnd = ptr + size;
    if (size == 0)
    {
        result.min = 0;
        result.max = 0;
        return result;
    }
    while (ptr < atEnd)
    {
        //++ptr;
        if (*ptr > *result.max) {result.max = ptr;}
        else if (*ptr < *result.min) {result.min = ptr;}
        ++ptr;
    }
    return result;
}


/////////////// STUDENT TESTING ////////////////////

int run()
{
    // Just some samples for class
    cout << "Try some code on your own" << endl;

    return 0;
}