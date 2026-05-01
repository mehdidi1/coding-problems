#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using ull = unsigned long long;
using Range = std::pair<ull, ull>;

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

ull mergeAndCountRanges(std::vector<Range> &ranges) {
    if (ranges.empty()) {
        return 0;
    }

    std::sort(ranges.begin(), ranges.end());

    std::vector<Range> mergedRanges;
    mergedRanges.push_back(ranges[0]);

    for (size_t i = 1; i < ranges.size(); ++i) {
        Range &lastMerged = mergedRanges.back();
        const Range &current = ranges[i];

        if (current.first <= lastMerged.second + 1) {
            lastMerged.second = std::max(lastMerged.second, current.second);
        } else {
            mergedRanges.push_back(current);
        }
    }

    ull totalLength = 0;
    for (const auto &range : mergedRanges) {
        totalLength += (range.second - range.first + 1);
    }

    return totalLength;
}

int main() {
    std::vector<Range> ranges;
    std::string inputLine;

    while (std::getline(std::cin, inputLine)) {
        if (inputLine.empty()) {
            break;
        }

        std::vector<std::string> strRanges = splitStringStream(inputLine, '-');
        if (strRanges.size() < 2) {
            continue;
        }

        Range range = {std::stoull(strRanges[0]), std::stoull(strRanges[1])};
        ranges.push_back(range);
    }

    ull result = mergeAndCountRanges(ranges);

    std::cout << result << std::endl;

    return 0;
}
