#include "parce.h"

parce parcer(int argc, char *argv[]) {
    parce p;
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            if (argv[i][1] == '-') {
                if (std::string(argv[i]) == "--length") p.l = std::strtol(argv[i + 1], nullptr, 10);
                else if (std::string(argv[i]) == "--width") p.w = std::strtol(argv[i + 1], nullptr, 10);
                else if (std::string(argv[i]) == "--input") p.input = argv[i + 1];
                else if (std::string(argv[i]) == "--output") p.output_dir = argv[i + 1];
                else if (std::string(argv[i]) == "--max-iter") p.max_iter = std::strtol(argv[i + 1], nullptr, 10);
                else if (std::string(argv[i]) == "--freq") p.f = std::strtol(argv[i + 1], nullptr, 10);
            } else {
                for (int j = 1; j <= (sizeof(argv[i]) / sizeof("-")); j++) {
                    switch (argv[i][j]) {
                        case 'l': {
                            p.l = std::strtol(argv[i + j], nullptr, 10);
                            continue;
                        }
                        case 'w': {
                            p.w = std::strtol(argv[i + j], nullptr, 10);
                            continue;
                        }
                        case 'i': {
                            p.input = argv[i + j];
                            continue;
                        }
                        case 'o': {
                            p.output_dir = argv[i + j];
                            continue;
                        }
                        case 'm': {
                            p.max_iter = std::strtol(argv[i + j], nullptr, 10);
                            continue;
                        }
                        case 'f': {
                            p.f = std::strtol(argv[i + j], nullptr, 10);
                            continue;
                        }
                    }
                }
            }
        }
    }
    return p;
}