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

const ll MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

template <typename T> void print_arr(const vector<T> &arr);
template <typename T> T mod(const T x, const T n);

ll fast_exp(ll a, ll b) {
    if (b == 0) {
        return 1;
    }
    if (b == 1) {
        return a;
    }
    ll temp = fast_exp(a, b / 2);
    if (b % 2 == 0) {
        return mod(temp * temp,MOD);
    } else {
        return mod(a*temp*temp,MOD);
    }
}
void solve() {
    ll n, m;
    cin >> n >> m;
    ll temp = n;
    n = n+m-1;
    m = temp-1;
    ll upper = 1;
    for (ll iii = 2; iii <= n; iii++) {
        upper *= mod(iii,MOD);
        upper = mod(upper, static_cast<ll>(MOD));
    }
    ll lower = 1;
    for (ll iii = n - m + 1; iii <= m; iii++) {
        lower *= mod(iii,MOD);
        lower = mod(lower, static_cast<ll>(MOD));
    }
    lower = fast_exp(lower,MOD-2);
    std::cout << mod(upper*lower,MOD) << "\n";
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
