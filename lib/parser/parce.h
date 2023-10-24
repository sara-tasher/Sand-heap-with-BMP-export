#include <cstdlib>
#include <cstdint>
#include <string>

struct parce {
    uint64_t f = 0;
    uint16_t w = 0;
    uint16_t l = 0;
    std::string input;
    std::string output_dir;
    uint64_t max_iter = 0;
};

parce parcer(int argc, char *argv[]);
