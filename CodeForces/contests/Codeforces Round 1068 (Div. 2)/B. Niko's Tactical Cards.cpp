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

    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    if (n == 0) {
        cout << 0 << "\n";
        return;
    }

    ll cur_max = max(0 - a[0], b[0] - 0);
    ll cur_min = min(0 - a[0], b[0] - 0);

    for (int i = 1; i < n; i++) {
        ll prev_max = cur_max;
        ll prev_min = cur_min;

        ll op1 = prev_max - a[i];
        ll op2 = b[i] - prev_min;
        ll op3 = prev_min - a[i];
        ll op4 = b[i] - prev_max;

        cur_max = max({op1, op2, op3, op4});
        cur_min = min({op1, op2, op3, op4});
    }

    cout << cur_max << "\n";
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
