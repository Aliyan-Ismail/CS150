/**
 *  @author Aliyan Ismail
 *  @date Spring 21 WPM
 *  @file h30.cpp
 */
#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;

string STUDENT = "aismail9"; // Add your Canvas/occ-email ID
#include "h30.h"

// Add your code here
Image::Image(const std::string& path) {load(path);}

Image::Image(unsigned width, unsigned height) : m_width(width), m_height(height), m_pixels(width * height) {}

unsigned Image::width() const {return m_width;}

unsigned Image::height() const {return m_height;}

unsigned Image::size() const {return m_pixels.size();}

Pixel* Image::begin()
{
    if (size() > 0) {return &m_pixels.front();}
    return nullptr;
}

Pixel* Image::end()
{
    if (size() > 0) {return begin() + size();}
    return nullptr;
}

void Image::fill(const Pixel& color) {for (auto& p : m_pixels) p = color;}

bool Image::load(const std::string& path)
{
    const int BPP = 4;
    int w, h, bpp;
    UC* temp = stbi_load(path.c_str(), &w, &h, &bpp, BPP);
    if (temp == nullptr) {return false;}
    Pixel * data = reinterpret_cast<Pixel*>(temp);
    m_width = w;
    m_height = h;
    m_pixels.resize(w * h);
    for (size_t i = 0, len = m_pixels.size(); i < len; ++i) {m_pixels[i] = data[i];}
    stbi_image_free(temp);
    return true;
}

bool Image::save(const std::string& path)
{
    auto pos = path.rfind(".");
    if (pos == string::npos) {return false;}
    string ext = path.substr(pos);
    for (auto& e : ext) {e = tolower(e);}
    if (ext == ".jpg") {return stbi_write_jpg(path.c_str(), width(), height(), 4, reinterpret_cast<UC*>(&m_pixels.front()), 100);}
    else if (ext == ".bmp") {return stbi_write_bmp(path.c_str(), width(), height(), 4, reinterpret_cast<UC*>(&m_pixels.front()));}
    else if (ext == ".png") {return stbi_write_png(path.c_str(), width(), height(), 4, reinterpret_cast<UC*>(&m_pixels.front()), width() * 4);}
    return false;
}


//////////////////////// STUDENT TESTING //////////////////////////
void info(const string& msg, const Image& img);

int run()
{
    cout << "Part 1: construct three images" << endl;
    Image empty;                    // empty image
    Image square(20, 20);           // square image
    Image lego("images/lego.png");  //  from file
    cout << " -- Success" << endl;

    cout << "\nPart 2: print size, width, height" << endl;
    info("empty", empty);
    info("square", square);
    info("lego", lego);

    cout << "\nPart 3: Modify some images" << endl;
    bool ok = empty.load("images/paris.jpg");
    string msg = "Loading paris into empty image. ";
    msg += ok ? "Success." : "Failed.";
    cout << msg << endl;
    info("empty", empty);

    Pixel fillColor{255, 127};
    square.fill(fillColor);

    cout << "\nPart 4: loop through an image in two ways." << endl;
    for (auto& p : empty) // grayscale paris
    {
        auto avg = (p.red + p.green + p.blue) / 3;
        p.red = p.green = p.blue = avg;
    }
    // Use an iterator loop to draw a cross on square
    int cw = square.width() / 2;
    int cv = square.size() / 2;
    int i = 1;
    for (auto itr = begin(square); itr != end(square); ++itr)
    {
        if (i % cw == 0 || (i > cv - cw && i < cv + cw))
            *itr = GRAY;
        i++;
    }

    cout << "\nPart 5: Save all the pictures." << endl;
    auto parisOK = empty.save("actual/paris.png");
    auto squareOK = square.save("actual/square.png");
    auto legoOK = lego.save("actual/lego.jpg");
    cout << "paris.png " << (parisOK ? "saved" : "failed") << endl;
    cout << "square.png " << (squareOK ? "saved" : "failed") << endl;
    cout << "lego.jpg " << (legoOK ? "saved" : "failed") << endl;

    return 0;
}

void info(const string& msg, const Image& img)
{
    cout << msg << ": size()->" << img.size()
        << ", width()->" << img.width()
        << ", height()->" << img.height() << endl;
}
