#include <cmath>
#include <iostream>
#include <iterator>
#include <ostream>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using ll = long long;

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

ll dupPattern(ll pattern, int nbDups) {
    int n = std::log10(pattern) + 1;
    ll result{pattern};
    for (int jjj = 0; jjj < nbDups - 1; jjj++) {
        for (int iii = 0; iii < n; iii++) {
            result *= 10;
        }
        result += pattern;
    }
    return result;
}

int main(int argc, char *argv[]) {
    std::vector<int> primes = {2,  3,  5,  7,  11, 13, 17, 19, 23,
                               29, 31, 37, 41, 43, 47, 53, 59, 61,
                               67, 71, 73, 79, 83, 89, 97};
    std::string input;
    std::cin >> input;
    std::vector<std::string> ranges = splitStringStream(input, ',');

    std::set<ll> uniqueInvalidIDs;

    for (std::string range : ranges) {
        std::vector<std::string> sBounds = splitStringStream(range, '-');
        ll upperBound = std::stoll(sBounds[1]);
        ll lowerBound = std::stoll(sBounds[0]);
        ll pattern;
        int primeIdx{0};
        int dividor{2};
        while (dividor <= sBounds[1].size()) {
            if (sBounds[0].size() % dividor != 0) {
                pattern = std::pow(10, sBounds[0].size() / dividor);
            } else {
                pattern = std::stoll(
                    sBounds[0].substr(0, sBounds[0].size() / dividor));
            }

            ll fullNum = dupPattern(pattern, dividor);

            while (fullNum <= upperBound) {
                if (fullNum >= lowerBound) {
                    uniqueInvalidIDs.insert(fullNum);
                }
                pattern = pattern + 1;
                fullNum = dupPattern(pattern, dividor);
            }
            primeIdx++;
            dividor = primes[primeIdx];
        }
    }

    ll result{0};
    for (const auto &id : uniqueInvalidIDs) {
        result += id;
    }
    std::cout << result << std::endl;

    return 0;
}
