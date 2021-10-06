/**
    @file h32.h
    @author Stephen Gilbert
    @version Declarations for CS 150 Homework
*/
#ifndef H32_H_
#define H32_H_

#include <vector>

using UC = unsigned char;
struct Pixel {UC red=0, green=0, blue=0, alpha=255;};
const Pixel GRAY{128, 128, 128, 255};
const Pixel TRANSPARENT{0, 0, 0, 0};

class Image
{
public:
    Image() = default;
    explicit Image(const std::string& path);
    Image(unsigned width, unsigned height);

    unsigned width() const;
    unsigned height() const;
    unsigned size() const;

    Pixel* begin();
    Pixel* end();

    void fill(const Pixel& color);

    // New for this exercise
    /**
     * Rotates an image in both the dx and dy directions.
     * Pixels wrap around as required.
     * @param dx the amount to shift in the x dimension.
     * @param dy the amount to shift in the y dimension
     * Assume 4 bits per pixel
     */
    void translate(int dx, int dy);

    /**
     * Overloaded subscript operators.
     * @param idx index from 0 < size
     * @throws out_of_range if invalid index
     */
    const Pixel& operator[](unsigned idx) const;
    Pixel& operator[](unsigned idx);

    // Write the operators above this

    bool load(const std::string& path);
    bool save(const std::string& path);
    bool operator==(const Image& rhs);
private:
    unsigned m_width{0}, m_height{0};
    std::vector<Pixel> m_pixels;
};

// Functions from stb_image and stb_image_write
// These are C functions
extern "C" {
unsigned char* stbi_load(const char* fileName,
    int* width, int* height, int* bitsPerChannel,
    int desiredBpp=4);

 int stbi_write_png(const char* fName, int width, int height,
    int comp, const void *data, int stride);
 int stbi_write_bmp(const char* fName, int width, int height,
    int comp, const void *data);
 int stbi_write_jpg(const char* fName, int width, int height,
    int comp, const void *data, int quality);

 void stbi_image_free (void *);
};

#endif
