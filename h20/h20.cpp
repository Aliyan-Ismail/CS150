/**
 *  @author Aliyan Ismail
 *  @date Spring 2021 WPM
 *  @file h20.cpp
 */
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string STUDENT = "aismail9"; // Add your Canvas/occ-email ID

#include "h20.h"

// Add your code here
/**
 * Sets all green pixels to transparent.
 * A pixel is green if the green component is at least twice as large
 * as the maximum of its red and blue components.
 * @param data a constant pointer to the image data.
 * @param width the width of the image in pixels
 * @param height the height of the image in pixels
 * Assume that there are 4 bytes per pixel (RGBA)
 */
void greenScreen(unsigned char * const img, int width, int height)
{
    const int BPP = 4;
    unsigned char * p = img;
    auto * end = (img + width * height * BPP);
    while (p != end)
    {
        if (p[1] > (2 * max(p[0], p[2])))
        {
            p[0] = 0;
            p[1] = 0;
            p[2] = 0;
            p[3] = 0;
        }
        p += 4;
    }
}



/////////////// STUDENT TESTING ////////////////////
int run()
{
    // Write your own tests here
    
    return 0;
}