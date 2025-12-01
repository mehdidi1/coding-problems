#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

template <typename T> void print_arr(const vector<T> &arr);

struct SubarrayResult {
    long long maxSum;
    int startIndex;
    int endIndex;
};

SubarrayResult maxSubArray(const std::vector<int> &nums) {
    long long max_so_far = nums[0];
    long long current_max = nums[0];
    int start_index = 0;
    int end_index = 0;
    int temp_start_index = 0;

    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] > current_max + nums[i]) {
            current_max = nums[i];
            temp_start_index = i;
        } else {
            current_max += nums[i];
        }

        if (current_max > max_so_far) {
            max_so_far = current_max;
            start_index = temp_start_index;
            end_index = i;
        }
    }

    return {max_so_far, start_index, end_index};
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    SubarrayResult res = maxSubArray(a);
    if (k == 1) {
        int maxi = INT_MIN;
        int idx = -1;
        if (res.endIndex < n - 1) {
            maxi = max(maxi, abs(b[res.endIndex + 1]));
            idx = res.endIndex + 1;
        }
        if (res.startIndex > 0) {
            maxi = max(maxi, abs(b[res.endIndex - 1]));
            idx = res.endIndex - 1;
        }
        if (idx != -1) {
            a[idx] += abs(b[idx]);
            res = maxSubArray(a);
            cout << res.maxSum << endl;
            return;
        }
    }
    int maxb = b[res.startIndex];
    for (int iii = res.startIndex; iii <= res.endIndex; iii++) {
        maxb = max(maxb, abs(b[iii]));
    }
    if (k % 2 == 0) {
        cout << res.maxSum << endl;
    } else {
        cout << res.maxSum + maxb << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

template <typename T> void print_arr(const vector<T> &arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i];
        if (i + 1 < arr.size())
            cout << " ";
    }
    cout << endl;
}
