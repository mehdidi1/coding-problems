#include <iostream>
#include <vector>

using mat = std::vector<std::vector<int>>;
using ll = long long;

void printMap(const mat &map) {
    for (const auto &row : map) {
        for (const auto &cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char *argv[]) {
    int n = 138;
    mat map(n, std::vector<int>(n));
    mat exists(n, std::vector<int>(n));
    std::string inputLine;
    int lineNum{0};
    while (std::cin >> inputLine) {
        for (int colNum = 0; colNum < n; colNum++) {
            if (inputLine[colNum] == '@') {
                exists[lineNum][colNum] = 1;
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        if (lineNum + dx < n && lineNum + dx >= 0 &&
                            colNum + dy >= 0 && colNum + dy < n) {
                            if (dx != 0 || dy != 0)
                                map[lineNum + dx][colNum + dy]++;
                        }
                    }
                }
            }
        }
        lineNum++;
    }

    /* printMap(map); */
    ll result{};

    for (int iii = 0; iii < n; iii++) {
        for (int jjj = 0; jjj < n; jjj++) {
            if (map[iii][jjj] < 4 && exists[iii][jjj]) {
                result++;
            }
        }
    }
    std::cout << result << std::endl;

    return 0;
}
