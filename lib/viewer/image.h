#include <iostream>
#include <vector>
#include <string>
#include <fstream>

struct Matrix {
    uint64_t **array;
};

struct Color {
    unsigned char red = 0;
    unsigned char green = 0;
    unsigned char blue = 0;
};

struct Image {
    uint16_t w = 0;
    uint16_t l = 0;
    std::vector<Color> pixels;
};

Image create_image(uint16_t w, uint16_t l, Matrix &array);

void save_to_file(Image &img, const std::string &filename);
