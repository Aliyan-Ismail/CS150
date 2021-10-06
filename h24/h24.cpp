/**
 *  @author Aliyan Ismail
 *  @date Spring 21 WPM
 *  @file h24.cpp
 */
#include <string>
#include <stdexcept>
// Other headers if necessary
using namespace std;

string STUDENT = "aismail9"; // Add your Canvas/occ-email ID

#include "h24.h"

// Add your code here
/**
 * sameSet: checks if a and b have the same set of ints.
 *  - ignores multiplicity and order.
 *
 * @param a array of const int.
 * @param aEnd a pointer to past-the-end of a.
 * @param b array of const int.
 * @param bEnd pointer to past-the-end of b.
 *
 * @pre #aEnd and #bEnd are > a and b
 *
 * @return true if a and b have the "same set" as described above.
 * @examples:
 *      1  4  9  16  9  7  4  9  11 and 11  11  7  9  16  4  1 are same set
 *      3 1 1 11 and 3 11 11 7 are not the same set because b contains a 7
 *
 */
bool sameSet(const int *aBeg, const int *aEnd, const int *bBeg, const int *bEnd)
{
    bool result = false;
    bool found = false;

    for (const int *p = aBeg; *p != *aEnd; p++)
    {
        found = false;
        for (const int *q = bBeg; *q != *bEnd; q++)
        {
            if (*q == *p) {found = true; break;}
        }
        if (found == false) {result = false; break;}
        else {result = true;}
    }
    
    result = false;
    found = false;
    for (const int *p2 = bBeg; *p2 != *bEnd; p2++)
    {
        found = false;
        for (const int *q2 = aBeg; *q2 != *aEnd; q2++)
        {
            if (*q2 == *p2) {found = true; break;}
        }
        if (found == false) {result = false; break;}
        else {result = true;}
    }
    
    return result;
}

/**
 * Copies all even numbers from a to b.
 *
 * @param a array of const int.
 * @param aSize size of array a.
 * @param[out] b array of int to be filled in with even numbers.
 * @param[int, out] bSize declared size of b on entry; returns number of elements copied.
 *
 * @pre bSize >= aSize
 * @post b filled with even numbers from a.
 *      bSize set to number of even values copied.
 *
 * @throw illegal_length exception if size of b < size of a
 *
 */
void copyEvens(const int a[], size_t aSize, int b[], size_t& bSize)
{
    if (bSize < aSize)
    {
        throw length_error("B is not big enough to store all of the values in A");
    }

    bSize = 0;
    for (size_t i = 0; i < aSize; ++i)
    {
        if (a[i] % 2 == 0) {b[bSize++] = a[i];}
    }
}


/////////////// STUDENT TESTING ////////////////////
#include <iostream>
int run()
{
    cout << "Student testing" << endl;
    return 0;
}