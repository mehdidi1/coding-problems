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
    int n;
    cin >> n;
    vi a(n);
    vi seenMax(n);
    int max = INT_MIN;
    for (int iii = 0; iii < n; iii++) {
        cin >> a[iii];
        if (a[iii] > max) {
            max = a[iii];
        }
        seenMax[iii] = max;
    }
    ll result = 0;
    for (int iii = 1; iii < n; iii += 2) {
        if (seenMax[iii] <= a[iii - 1]) {
            result += a[iii - 1] - seenMax[iii] + 1;
            a[iii - 1] = seenMax[iii] - 1;
        }
        if (iii + 1 < n && seenMax[iii] <= a[iii + 1]) {
            result += a[iii + 1] - seenMax[iii] + 1;
            a[iii + 1] = seenMax[iii] - 1;
        }
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
