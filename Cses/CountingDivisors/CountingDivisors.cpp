#include <bits/stdc++.h>
#include <unordered_map>
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
template <typename T> T mod(T x, T n);

void solve() {
    ll n;
    cin >> n;
    vi sieve(10e6 + 2);
    double bound = std::sqrt(sieve.size());
    for (int iii = 2; iii < bound; iii++) {
        if (sieve[iii] == 0) {
            int mult = 2;
            while (iii * mult < sieve.size()) {
                sieve[iii * mult] = iii;
                mult++;
            }
        }
    }
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        std::unordered_map<int, int> prime_div;
        while (sieve[a[i]] != 0) {
            /* cout << a[i] << "\n"; */
            prime_div[sieve[a[i]]]++;
            a[i] = a[i] / sieve[a[i]];
        }
        /* cout << a[i] << "\n"; */
        if (a[i] > 1)
            prime_div[a[i]]++;
        int result = 1;
        for (auto &[key, value] : prime_div) {
            result *= (value + 1);
        }
        cout << result << "\n";
    }
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
