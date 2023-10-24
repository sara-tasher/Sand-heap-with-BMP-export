#include "sand.h"

void sand(Matrix &matrix, parce &p) {

    std::queue<std::pair<uint16_t, uint16_t >> q;

    uint16_t x, y;
    uint64_t value;
    std::ifstream fin(p.input);

    while (fin >> x >> y >> value) {
        matrix.array[x - 1][y - 1] = value;
        if (value >= 4) q.push(std::make_pair(x - 1, y - 1));
    }

    int num_of_iteration = 0;

    while (!q.empty()) {

        auto len = q.size();
        for (int i = 0; i < len; i++) {
            matrix.array[q.front().first][q.front().second] -= 4;
            if (matrix.array[q.front().first][q.front().second] >= 4) q.push(q.front());

            if (q.front().first > 0) {
                matrix.array[q.front().first - 1][q.front().second]++;
                if (matrix.array[q.front().first - 1][q.front().second] == 4)
                    q.push(std::make_pair(q.front().first - 1, q.front().second));
            }
            if (q.front().first < p.l - 1) {
                matrix.array[q.front().first + 1][q.front().second]++;
                if (matrix.array[q.front().first + 1][q.front().second] == 4)
                    q.push(std::make_pair(q.front().first + 1, q.front().second));
            }
            if (q.front().second > 0) {
                matrix.array[q.front().first][q.front().second - 1]++;
                if (matrix.array[q.front().first][q.front().second - 1] == 4)
                    q.push(std::make_pair(q.front().first, q.front().second - 1));
            }
            if (q.front().second < p.w - 1) {
                matrix.array[q.front().first][q.front().second + 1]++;
                if (matrix.array[q.front().first][q.front().second + 1] == 4)
                    q.push(std::make_pair(q.front().first, q.front().second + 1));
            }
            q.pop();
        }
        num_of_iteration++;
        if (num_of_iteration == p.max_iter) {
            save_image(num_of_iteration / p.f, p, matrix);
            exit(0);
        }
        if (num_of_iteration % p.f == 0) {
            save_image(num_of_iteration / p.f, p, matrix);
        }
    }
}

void save_image(uint64_t number, parce &p, Matrix &matrix) {
    Image image = create_image(p.w, p.l, matrix);

    std::string filename;
    filename += p.output_dir;
    filename += std::to_string(number);
    filename += ".bmp";
    save_to_file(image, filename);
}