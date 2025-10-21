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

void solve() {
    ll a, b;
    cin >> a >> b;
    vi result;
    if (__builtin_clz(a) > __builtin_clz(b)) {
        cout << -1 << endl;
        return;
    } else {
        int i = 0;
        while ((a >> i) > 0) {
            if ((a >> i) % 2 != (b >> i) % 2) {
                result.push_back(1 << i);
            }
            i++;
        }
    }
    cout << result.size() << endl;
    for (int num : result) {
        cout << num << " ";
    }
    if (result.size() != 0)
        cout << endl;
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
