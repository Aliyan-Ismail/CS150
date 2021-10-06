/**
 *  @author Aliyan Ismail
 *  @date Spring 21 WPM
 *  @file h28.cpp
 */
#include <string>
using namespace std;

string STUDENT = "aismail9"; // Add your Canvas/occ-email ID

#include "h28.h"

// Implement your class here
Bug::Bug(int startPos)      // construct Bug at starting position
{
    m_position = startPos;
}

void Bug::move()            // move bug one unit in direction
{
    if (m_direction >= 0) {m_position++;}
    else {m_position--;}
}

void Bug::turn()            // Change the direction from left to right or vice-versa
{
    if (m_direction >= 0) {m_direction = -1;}
    else {m_direction = 0;}
}

int Bug::position() const   // Return the position
{
    return m_position;
}



//////////////////////// STUDENT TESTING //////////////////////////
#include <iostream>
int run()
{
    cout << "Add your own tests here" << endl;
    // Bug fred(3);
    // fred.move();
    // cout << "fred is now at " << fred.position() << endl;

    return 0;
}