/**
 *  @author Aliyan Ismail
 *  @date Spring 2021 WPM
 *  @file h19.cpp
 */
#include <string>
#include <iostream>
using namespace std;

string STUDENT = "aismail9"; // Add your Canvas/occ-email ID


#include "h19.h"

// Add your code here
/**
 * Reverses (inverts) every pixel in img, except any alpha pixels.
 * @param data a constant pointer to the image data.
 * @param width the width of the image in pixels
 * @param height the height of the image in pixels
 * Assume 4 bits per pixel
 */
void negative(unsigned char * const img, int width, int height)
{
    const int BPP = 4;
    unsigned char * p = img;
    // *p = 255 - *p;
    // p++;
    // *p = 255 - *p;
    // p++;
    // *p = 255 - *p;
    // p++;
    // p++;
    const auto * end = img + width * height * BPP;
    while (p != end)
    {
        *p = 255 - *p;
        p++;
        *p = 255 - *p;
        p++;
        *p = 255 - *p;
        p++;
        p++;
    }
}


/////////////// STUDENT TESTING ////////////////////
int run()
{
    // Just some samples for class
    cout << "Load images/paris.jpg" << endl;
    // 1. Load a jpg file using 4 bytes per pixel (bpp RGBA)
    int width, height, bpp, channels = 4;
    unsigned char * paris =
        stbi_load("images/paris.jpg",       // input file
                    &width, &height, &bpp,  // pointers (out)
                    channels);              // channels (in)

    // Now write it out in current folder as a 4-bytes-per-pixel PNG
    if (stbi_write_png("paris.png", width, height, channels, paris,
                    width * channels))
        cout << "Find paris.png in current folder." << endl;
    else
        cout << "Couldn't write paris.png" << endl;

    // IMPORTANT - free the memory
    stbi_image_free(paris);

    // 2. Load a png file using 1 byte per pixel (Gray scale)
    cout << "Loading images/stegosuarus.png as gray scale." << endl;
    channels = 1;
    unsigned char * stego = stbi_load("images/stegosaurus.png",
                                &width, &height, &bpp, channels);
    cout << "Writing as stego-bw.bmp in current folder: ";
    if (stbi_write_bmp("stego-bw.bmp", width, height, channels, stego))
        cout << "Success!" << endl;
    else cout << "Failed!" << endl;

    stbi_image_free(stego);

    // 3. Load a png file using 3 bytes (RGB only)
    cout << "Load images/Vermeer-Milkmaid.png, 3 bpp." << endl;
    channels = 3;
    int quality = 50; // medium quality jpg
    auto vermeer = stbi_load("images/Vermeer-Milkmaid.png", &width, &height, &bpp, channels);
    stbi_write_jpg("vermeer.jpg", width, height, channels, vermeer, quality);
    stbi_image_free(vermeer);
    cout << "Saved as vermeer.jpg in current folder." << endl;

    return 0;
}