#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
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
template <typename T> T mod(T x, T n);

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> prefix(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    prefix[0] = mod(a[0], n);
    for (int iii = 1; iii < n; iii++) {
        prefix[iii] += mod(prefix[iii - 1] + a[iii],n);
    }
    prefix.insert(prefix.begin(), 0);
    /* print_arr(prefix); */
    ull result = 0;
    map<int, ull> mem;
    for (int iii = 0; iii < n + 1; iii++) {
        result += mem[prefix[iii]];
        mem[prefix[iii]]++;
    }
    std::cout << result << std::endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    /* cin >> t; */
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

template <typename T> T mod(T x, T n) { return ((x % n) + n) % n; }
