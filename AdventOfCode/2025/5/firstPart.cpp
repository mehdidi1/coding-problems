#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using ull = unsigned long long;

std::vector<std::string> splitStringStream(const std::string &str,
                                           char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::stringstream ss(str);

    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    std::vector<std::pair<ull, ull>> ranges;
    std::string inputLine;

    // --- PHASE 1: Reading ranges, stopping at the first empty line ---
    while (std::getline(std::cin, inputLine)) {
        if (inputLine.empty()) {
            break;
        }

        std::vector<std::string> strRanges = splitStringStream(inputLine, '-');

        std::pair<ull, ull> range = {std::stoull(strRanges[0]),
                                     std::stoull(strRanges[1])};
        ranges.push_back(range);
    }

    // --- PHASE 2: Reading IDs ---
    ull result{};

    while (std::cin >> inputLine) {
        ull id = std::stoull(inputLine);
        /* std::cerr << id << std::endl; */
        for (const std::pair<ull, ull> &range : ranges) {
            if (id >= range.first && id <= range.second) {
                result++;
                break;
                /* std::cerr << id << std::endl; */
            }
        }
    }

    std::cout << result << std::endl;

    return 0;
}
