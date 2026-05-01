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

void solve() {
    ll n, h, k;
    cin >> n >> h >> k;
    vector<ll> a(n);
    vll prefix(n);
    vll max(n);
    vll min(n);
    min[0] = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i != 0) {
            prefix[i] += prefix[i - 1] + a[i];
            min[i] = std::min(min[i - 1], a[i]);
        } else {
            prefix[i] = a[i];
            min[i] = a[i];
        }
    }
    ll result = h % prefix.back();
    max[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        max[i] = std::max(max[i + 1], a[i + 1]);
    }
    for (int iii = 0; iii < n; iii++) {
        prefix[iii] = prefix[iii] + max[iii] - min[iii];
    }
    int i = 0;
    while (i < n && h % prefix.back() - prefix[i] > 0) {
        i++;
    }
    result = (h / prefix.back()) * k + i;
    /* print_arr(prefix);
    print_arr(max);
    print_arr(min); */
    std::cout << result << std::endl;
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
