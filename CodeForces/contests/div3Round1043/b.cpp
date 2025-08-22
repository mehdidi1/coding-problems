#include <algorithm>
#include <charconv>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <ostream>
#include <set>
#include <tuple>
#include <vector>

// Main entry point
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        long long n;
        std::cin >> n;
        int result = 0;
        std::vector<long long> values;
        for (int i = 1; i < std::to_string(n).size(); i++) {
            long long power = std::pow(10,i);

            if (n % (1 + power) == 0) {
                result++;
                values.push_back(n/(1 + power)); 
            }
        }
        std::cout << result << std::endl;
        std::sort(values.begin(),values.end());
        for (auto v : values) std::cout << v << " ";
        std::cout << std::endl;
    }
    return 0;
}
