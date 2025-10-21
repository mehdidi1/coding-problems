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
void solve() {
    ll x, y, z;
    cin >> x >> y >> z;
    ll val = x ^ y ^ z;
    ll mask = (x | y | z);
    string result = "YES\n";
    if ((~val & mask) != 0)
        result = "NO\n";
    cout << result;
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
