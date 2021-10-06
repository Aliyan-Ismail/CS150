/**
 *  @author Aliyan ismail
 *  @date Spring 2021 WPM
 *  @file h21.cpp
 */
#include <string>
#include <iostream>
using namespace std;

string STUDENT = "aismail9"; // Add your Canvas/occ-email ID

#include "h21.h"

// Add your code here
/**
 * Combines a background and foreground. The foreground
 * is "green-screened". The pixels are combined with
 * opaque pixels from foreground and backround showing
 * through the transparent ones.
 * @param data a constant pointer to the image data.
 * @param width the width of the image in pixels
 * @param height the height of the image in pixels
 *  - Assume that there are 4 bytes per pixel (RGBA)
 *  - Asume both images are the same size.
 */
void composite( unsigned char * const bg, unsigned char * const fg, int width, int height)
{
    const int BPP = 4;
    greenScreen(fg, width, height);
    unsigned char * dest = fg;
    unsigned char * src = bg;
    const auto * end = (fg + width * height * BPP);
    while (dest != end)
    {
        if (dest[0] == 0 && dest[1] == 0 && dest[2] == 0 && dest[3] == 0)
        {
            dest[0] = src[0];
            dest[1] = src[1];
            dest[2] = src[2];
            dest[3] = src[3];
        }
        src += 4;
        dest += 4;
    }
    
    
}






/////////////// STUDENT TESTING ////////////////////

int run()
{
    // Add your own testing code here

    return 0;
}