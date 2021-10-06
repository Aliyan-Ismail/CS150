/**
 *  @author Aliyan Ismail
 *  @date Spring 21 WPM
 *  @file h32.cpp
 */
#include <string>
#include <iostream>
using namespace std;

string STUDENT = "aismail9"; // Add your Canvas/occ-email ID


#include "h32.h"

// Add your code here
const Pixel& Image::operator[](unsigned idx) const
{
    return m_pixels.at(idx);
}

Pixel& Image::operator[](unsigned idx)
{
    return m_pixels.at(idx);
}

void Image::translate(int dx, int dy)
{
    Image& img = *this;
    int countx = 1;
    int county = 0;
    
    if (dx < 0) {dx = width() - abs(dx) % width();}
    else {dx = dx % width();}
    
    if (dy < 0) {dy = height() - abs(dy) % height();}
    else {dy = dy % height();}
    
    for (size_t row = 0; row < height(); row++)
    {
        for (int i = 1; i <= dx; i++)
        {
            int last = ((row + 1) * width()) - 1;
            Pixel temp(m_pixels.at(last));
            for (size_t col = width() - 1; col > 0; col--)
            {
                int index = row * width() + col;
                m_pixels.at(index) = m_pixels.at(index - 1);
            }
            m_pixels.at(row * width()) = temp;
            countx++;
        }
    }
    
    auto lastRow = m_width * (m_height - 1);
    while (county < dy)
    {
        for (unsigned int col = 0; col < m_width; ++col)
        {
            auto temp2 = img[lastRow + col];
            for (auto row = m_height - 1; row > 0; --row)
            {
                img[row * m_width + col] = img[(row - 1) * m_width + col];
            }
            img[col] = temp2;
        }
        county++;
    }
}


/////////////// STUDENT TESTING ////////////////////

int run()
{
    // Just some samples for class
    cout << "Try some code on your own" << endl;

    return 0;
}