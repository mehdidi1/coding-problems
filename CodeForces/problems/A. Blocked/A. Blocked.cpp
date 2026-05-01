#include <algorithm>
#include <bits/stdc++.h>
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
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<bool> present(100);
    bool res = true;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (present[a[i]]) {
            res = false;
        }
        present[a[i]] = 1;
    }
    if (res) {
        std::sort(a.begin(), a.end(), std::greater<ll>());
        print_arr(a);
    } else {
        std::cout << -1 << std::endl;
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
