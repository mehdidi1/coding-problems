#include <algorithm>
#include <cmath>
#include <cstdlib>
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
        std::cin >> n;
        std::vector<int> p(n);
        for (int i = 0; i < n; i++) {
            std::cin >> p[i];
        }
        int max_i;
        for (int i = 0; i < n; i++) {
            if (p[i] == n) {
                max_i = i;
                break;
            }
        }
        int min_sub = max_i;
        int max_sub = max_i;
        int last = n;
        while (max_sub - min_sub <= n - 1) {
            if (max_sub < n - 1 && p[max_sub + 1] == last - 1) {
                max_sub++;
                last--;
            } else if (min_sub > 0 && p[min_sub - 1] == last - 1) {
                min_sub--;
                last--;
            }
            else {
            break;
            }
        }
        if (last == 1 ){
            std::cout << "YES\n";
        }
        else {
            std::cout << "NO\n";
        }
    }
    return 0;
}

