#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>

using ll = long long;

std::vector<int> consecutiveMax(std::vector<int> tab) {
    int nbMaxes = 12;
    std::vector<int> maxes(12);
    int n = tab.size();
    for (int iii = 0; iii < n; iii++) {
        int elementsLeft = std::min(nbMaxes, n - iii);
        for (int jjj = nbMaxes - elementsLeft; jjj < nbMaxes; jjj++) {
            if (tab[iii] > maxes[jjj]) {
                maxes[jjj] = tab[iii];
                for (int kkk = jjj + 1; kkk < nbMaxes; kkk++) {
                    maxes[kkk] = 0;
                }
                break;
            }
        }
    }
    return maxes;
}

ll arrToNum(std::vector<int> vec) {
    ll result{};
    for (int iii = 0; iii < vec.size(); iii++) {
        result += vec[iii] * std::pow(10, vec.size() - 1 - iii);
    }
    return result;
}

std::vector<int> splitDigits(std::string s) {
    std::vector<int> result;
    for (char c : s) {
        result.push_back(c - '0');
    }
    return result;
}

int main(int argc, char *argv[]) {
    std::string inputLine;
    ll result{0};
    while (std::cin >> inputLine) {
        std::vector<int> digits = splitDigits(inputLine);
        std::vector<int> maxes = consecutiveMax(digits);
        result += arrToNum(maxes);
        std::cerr << "num : " << arrToNum(maxes) << std::endl;
    }
    std::cout << result << std::endl;
    return 0;
}
