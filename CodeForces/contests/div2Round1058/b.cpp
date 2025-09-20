#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        int n;
        int k;
        std::cin >> n >> k;
        std::vector<int> prices(n);
        for (int i = 0; i < n; i++) {
            std::cin >> prices[i];
        }
        std::vector<int> vouchers(k);
        for (int i = 0; i < k; i++) {
            std::cin >> vouchers[i];
        }
        std::sort(vouchers.begin(), vouchers.end());
        std::sort(prices.begin(), prices.end(), std::greater<>());
        long long result = 0;
        int idx = 0;
        int idx_v = 0;
        while (idx < n) {
            if (idx_v < vouchers.size() && vouchers[idx_v]<= (prices.size()-idx)) {
                for (int i = 0; i < vouchers[idx_v] - 1; i++) {
                    result = result + prices[idx + i];
                }
                idx = idx + vouchers[idx_v];
                idx_v++;
            } else {
                result = result + prices[idx];
                idx++;
            }
        }
        std::cout << result << std::endl ;
    }
    return 0;
}

