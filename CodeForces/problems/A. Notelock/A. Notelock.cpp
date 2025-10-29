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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int result = 0;
    int streak = 0;
    for (int iii = 0; iii < n; iii++) {
        if (s[iii] == '1') {
            if (streak >= k - 1 || streak == iii) {
                result++;
            }
            streak = 0;

        } else {
            streak++;
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
