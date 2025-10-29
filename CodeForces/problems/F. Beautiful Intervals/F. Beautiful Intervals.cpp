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
    int m, n;
    cin >> n >> m;
    vi occ(n);
    for (int iii = 0; iii < m; iii++) {
        int l, r;
        cin >> l >> r;
        for (int jjj = l; jjj <= r; jjj++) {
            occ[jjj - 1]++;
        }
    }

    for (int iii = 0; iii < n; iii++) {
        cout << occ[iii];
        cout << " ";
    }
    cout << endl;
    vi result(n);
    int nexNum = 0;
    int maxIdx = 0;
    for (int iii = 0; iii < n; iii++) {
        int max = INT_MIN;
        for (int jjj = 0; jjj < n; jjj++) {
            if (max < occ[jjj]) {
                max = occ[jjj];
                maxIdx = jjj;
            }
        }
        result[maxIdx] = nexNum;
        occ[maxIdx] = INT_MIN;
        nexNum++;
    }
    for (int iii = 0; iii < n; iii++) {
        cout << result[iii];
        cout << " ";
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
