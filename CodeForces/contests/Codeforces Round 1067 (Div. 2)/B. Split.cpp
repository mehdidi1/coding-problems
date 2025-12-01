#include <bits/stdc++.h>
#include <exception>
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
    vector<ll> a(n * 2);
    vll occ(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
        occ[a[i]]++;
    }
    ll result = 0;
    ll odd = 0;
    ll even = 0;
    for (int iii = 0; iii < 2 * n; iii++) {
        if (occ[iii] == 0) {
            continue;
        }
        if (occ[iii] % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }
    result = odd + 2 * even;
    if (odd % 2 == 0) {
        result--;
    }
    cout << result << endl;
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
