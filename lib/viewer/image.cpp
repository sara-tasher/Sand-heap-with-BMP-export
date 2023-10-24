#include "image.h"

const Color kWHITE{255, 255, 255};
const Color kBLACK{0, 0, 0};
const Color kGREEN{0, 214, 120};
const Color kPURPLE{129, 0, 255};
const Color kYELLOW{255, 237, 0};

Image create_image(uint16_t w, uint16_t l, Matrix &matrix) {
    Image img;
    img.w = w;
    img.l = l;
    img.pixels.resize(w * l);
    for (int i = 0; i < w * l; i++) {
        switch (matrix.array[i / w][i % w]) {
            case 0 : {
                img.pixels[i] = kWHITE;
                break;
            }
            case 1 : {
                img.pixels[i] = kGREEN;
                break;
            }
            case 2 : {
                img.pixels[i] = kPURPLE;
                break;
            }
            case 3 : {
                img.pixels[i] = kYELLOW;
                break;
            }
            default : {
                img.pixels[i] = kBLACK;
                break;
            }
        }
    }
    return img;
}

void save_to_file(Image &img, const std::string &filename) {
    std::ofstream f;
    f.open(filename, std::ios::out | std::ios::binary);
    if (!f.is_open()) {
        std::cout << "Error: file could not be opened\n";
        exit(-1);
    }
    unsigned int w = img.w;
    unsigned int l = img.l;
    unsigned short d = w % 4;
    unsigned char pad[3] = {0, 0, 0};
    unsigned char header[14];
    header[0] = 'B';
    header[1] = 'M';
    const int File_size = 54 + l * (3 * w + d);
    header[2] = File_size;
    header[3] = File_size >> 8;
    header[4] = File_size >> 16;
    header[5] = File_size >> 24;
    header[6] = 0;
    header[7] = 0;
    header[8] = 0;
    header[9] = 0;
    header[10] = 54;
    header[11] = 0;
    header[12] = 0;
    header[13] = 0;

    unsigned char header_info[40];
    header_info[0] = 40;
    header_info[1] = 0;
    header_info[2] = 0;
    header_info[3] = 0;
    header_info[4] = w;
    header_info[5] = w >> 8;
    header_info[6] = w >> 16;
    header_info[7] = w >> 24;
    header_info[8] = l;
    header_info[9] = l >> 8;
    header_info[10] = l >> 16;
    header_info[11] = l >> 24;
    header_info[12] = 1;
    header_info[13] = 0;
    header_info[14] = 24;
    header_info[15] = 0;
    header_info[16] = 0;
    header_info[17] = 0;
    header_info[18] = 0;
    header_info[19] = 0;
    header_info[20] = 0;
    header_info[21] = 0;
    header_info[22] = 0;
    header_info[23] = 0;
    header_info[24] = 0;
    header_info[25] = 0;
    header_info[26] = 0;
    header_info[27] = 0;
    header_info[28] = 0;
    header_info[29] = 0;
    header_info[30] = 0;
    header_info[31] = 0;
    header_info[32] = 0;
    header_info[33] = 0;
    header_info[34] = 0;
    header_info[35] = 0;
    header_info[36] = 0;
    header_info[37] = 0;
    header_info[38] = 0;
    header_info[39] = 0;

    f.write(reinterpret_cast<char *>(header), 14);
    f.write(reinterpret_cast<char *>(header_info), 40);
    for (int y = 0; y < l; y++) {
        for (int x = 0; x < w; x++) {
            auto r = static_cast<unsigned char>(img.pixels[x + w * y].red);
            auto g = static_cast<unsigned char>(img.pixels[x + w * y].green);
            auto b = static_cast<unsigned char>(img.pixels[x + w * y].blue);

            unsigned char color[] = {b, g, r};

            f.write(reinterpret_cast<char *>(color), 3);
        }
        f.write(reinterpret_cast<char *>(pad), d);
    }
    f.close();
}