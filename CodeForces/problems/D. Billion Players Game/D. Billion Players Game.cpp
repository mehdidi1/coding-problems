#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    long long l, r;
    if (!(cin >> n >> l >> r))
        return;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // We want to maximize min(Score(l), Score(r)).
    // Score(p) is linear, so the minimum is always at one of the boundaries.

    long long sum_L = 0;
    long long sum_R = 0;
    vector<long long> options; // Stores a_i for offers in [l, r]

    for (long long val : a) {
        if (val < l) {
            // val is to the left of the range.
            // We must bet p >= val (Profit: p - val).
            // Claiming <= would result in a guaranteed loss.
            sum_L += (l - val);
            sum_R += (r - val);
        } else if (val > r) {
            // val is to the right of the range.
            // We must bet p <= val (Profit: val - p).
            sum_L += (val - l);
            sum_R += (val - r);
        } else {
            // val is inside [l, r].
            // We assume the initial state is betting p >= val (Maximum slope).
            sum_L += (l - val);
            sum_R += (r - val);

            // For offers inside the interval, we can switch strategy:
            // 1. Switch from ">= val" to "Ignore"
            // 2. Switch from "Ignore" to "<= val"
            // Both steps increase sum_L by (val - l) and decrease sum_R by (r -
            // val). We push both steps as available options.
            options.push_back(val);
            options.push_back(val);
        }
    }

    // Greedy Strategy:
    // We want to increase sum_L (which starts low) while paying the smallest
    // cost from sum_R. Cost/Benefit ratio depends on a_i. Larger a_i (closer to
    // r) gives more boost to L for less drop in R. So we sort descending.
    sort(options.rbegin(), options.rend());

    long long ans = min(sum_L, sum_R);

    for (long long val : options) {
        // Optimization: If L has already overtaken R, increasing L further
        // while decreasing R will only lower the minimum (which is now R).
        if (sum_L >= sum_R)
            break;

        sum_L += (val - l);
        sum_R +=
            (val - r); // Note: val - r is negative or zero, so this reduces R

        ans = max(ans, min(sum_L, sum_R));
    }

    cout << ans << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
