#include <iostream>
#include "sand.h"


int main(int argc, char *argv[]) {

    parce p = parcer(argc, argv);

    auto **array = new uint64_t *[p.l];
    for (int i = 0; i < p.l; i++) {
        array[i] = new uint64_t[p.w];
    }
    Matrix matrix;
    matrix.array = array;
    for (int i = 0; i < p.l; i++) {
        for (int j = 0; j < p.w; j++) {
            array[i][j] = 0;
        }
    }
    sand(matrix, p);
    delete[] array;

}

