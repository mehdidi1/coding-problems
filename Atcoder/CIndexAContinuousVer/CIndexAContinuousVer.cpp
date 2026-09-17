#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define fi first
#define se second

constexpr ll MOD =
    998244353; // AtCoder's common modulus; swap to 1e9+7 if needed
constexpr ll INF = 4e18;

template <typename T> bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <typename T> bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}
template <typename T> T mod(T x, T n) { return ((x % n) + n) % n; }
template <typename T> void print_arr(const vector<T> &arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i];
        if (i + 1 < arr.size())
            cout << " ";
    }
    cout << endl;
}

#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << endl;
#else
#define dbg(x)
#endif

void solve() {
    int n, m;
    cin >> n >> m;
    vll a(n);
    rep(i, n) cin >> a[i];
    vector<ll> prefix(n + 1);
    prefix[0] = 0;
    for (int iii = 0; iii < n; iii++) {
        prefix[1 + iii] = prefix[iii] + a[iii];
    }
    ll result = 0;
    for (int iii = 0; iii < m; iii++) {
        result += (1 + iii) * a[iii];
    }
    /* print_arr(prefix); */
    /* print_arr(a); */
    /* std::cout << result << "\n"; */
    ll temp = result;
    for (int iii = m; iii < n; iii++) {
        temp = temp - (prefix[iii] - prefix[iii - m]) + m * a[iii];
        result = max(temp, result);
        /* std::cout << temp << "\n"; */
    }
    std::cout << result << std::endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);

    int t = 1;
    /* cin >> t; // comment this out if the problem has no multi-testcase count
     */
    while (t--)
        solve();

    return 0;
}
