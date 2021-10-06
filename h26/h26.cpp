/**
 *  @author Aliyan Ismail
 *  @date Spring 21 WPM
 *  @file h26.cpp
 */
#include <string>
#include <iostream>
#include <memory>
using namespace std;

string STUDENT = "aismail9"; // Add your Canvas/occ-email ID

#include "h26.h"
// Add your code here
/**
 * Read integers from a stream into a FlexArray.
 * @param[in] in the stream to read from.
 * @param[out] the FlexArray to store the data in
 * @return a reference to the modified FlexArray
 * @post size_ will contain the number of elements
 * @post data_ will contain exactly size_ elements
 * @post in will be at end of file or a non-integer
 */
FlexArray& readData(std::istream& in, FlexArray& a)
{
    size_t CAPACITY = INITIAL_CAPACITY;
    a.data_ = unique_ptr<int[]>(new int[CAPACITY]);
    int num = 0;
    size_t pos = 0;
    
    while (in >> num && !in.fail())
    {
        a.data_[pos] = num;
        pos++;
        a.size_++;
        if (a.size_ == CAPACITY)
        {
            unique_ptr<int[]> temp;
            temp.reset(a.data_.release());
            a.data_ = unique_ptr<int[]>(new int[CAPACITY *= 2]);
            for (size_t i = 0; i < a.size_; i++)
            {
                a.data_[i] = temp[i];
            }
        }
    }
    unique_ptr<int[]> temp;
    temp.reset(a.data_.release());
    a.data_ = unique_ptr<int[]>(new int[a.size_]);
    for (size_t i = 0; i < a.size_; i++) {a.data_[i] = temp[i];}
    return a;
}

/**
 * Return a string representation of a FlexArray.
 * @param a the array to represent.
 * @return a comma separated, brace delimited contents.
 */
std::string toString(const FlexArray& a)
{
    if (a.size_ == 0) {return "{}";}
    string result = "{";
    result += to_string(a.data_[0]);
    for (size_t i = 1; i < a.size_; i++) {result += ", " + to_string(a.data_[i]);}
    result += "}";
    return result;
}


//////////////////////// STUDENT TESTING //////////////////////////
#include <iostream>
#include <sstream>
int run()
{
    cout << "Add your own tests here" << endl;
    // istringstream in("8 9 Q 4 5");
    // FlexArray a;
    // in >> a;
    // cout << "a->" << a << endl;
    return 0;
}