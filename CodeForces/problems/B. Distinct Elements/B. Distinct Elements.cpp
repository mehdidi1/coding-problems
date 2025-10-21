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
    int n;
    cin >> n;
    vi b(n);
    for (int iii = 0; iii < n; iii++) {
        cin >> b[iii];
    }
    vi a(n);
    a[0] = 1;
    for (int iii = 1; iii < n; iii++) {
        int goal = a[iii - 1] + 1 + b[iii - 1];
        a[iii] = b[iii]
    }

    for (int iii = 0; iii < n; iii++) {
        cout << a[iii] << " ";
    }
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
