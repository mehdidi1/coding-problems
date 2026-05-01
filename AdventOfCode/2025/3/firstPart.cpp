#include <iostream>
#include <iterator>
#include <utility>
#include <vector>

using ll = long long;

std::pair<int, int> consecutiveMax(std::vector<int> tab) {
    int max1{};
    int max2{};
    int n = tab.size();
    for (int iii = 0; iii < n; iii++) {
        if (tab[iii] > max1 && iii != n - 1) {
            max1 = tab[iii];
            max2 = 0;
        } else if (tab[iii] > max2) {
            max2 = tab[iii];
        }
    }
    std::pair<int, int> result{max1, max2};
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
        std::pair<int, int> maxes = consecutiveMax(digits);
        /* std::cerr << "pairs : " << maxes.first << maxes.second << std::endl;
         */
        result += maxes.first * 10 + maxes.second;
    }
    std::cout << result << std::endl;
    return 0;
}
