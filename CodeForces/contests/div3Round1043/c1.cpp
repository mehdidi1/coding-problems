#include <algorithm>
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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    std::vector<long long> p3 = {1};
    while (p3.back() <= 1000000000) {
        p3.push_back(p3.back() * 3);
    }

    while (t--) {
        long long n;
        std::cin >> n;
        long long cost = 0;
        while (n > 0) {
            long long deal = std::upper_bound(p3.begin(), p3.end(), n) - p3.begin() - 1;
            n = n - p3[deal];
            cost = cost + p3[deal + 1] + deal * (deal > 0 ? p3[deal - 1] : 0);
        }
        std::cout << cost << std::endl;
    }
    return 0;
}
 
