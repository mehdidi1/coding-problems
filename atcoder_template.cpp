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

constexpr ll MOD = 998244353; // AtCoder's common modulus; swap to 1e9+7 if needed
constexpr ll INF = 4e18;

template <typename T>
bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template <typename T>
bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << endl;
#else
#define dbg(x)
#endif

void solve() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];

    // ---- solve here ----

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);

    int t = 1;
    cin >> t; // comment this out if the problem has no multi-testcase count
    while (t--) solve();

    return 0;
}
