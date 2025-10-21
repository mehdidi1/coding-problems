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
    if (n * n - 1 != k) {
        int charCount = 0;
        cout << "YES\n";
        for (int iii = 0; iii < k; iii++) {
            cout << "U";
            if ((iii + 1) % n == 0) {
                cout << endl;
            }
            charCount++;
        }
        for (int iii = k; iii < n * (n - 1); iii++) {

            cout << "D";
            if ((iii + 1) % n == 0) {
                cout << endl;
            }
            charCount++;
        }
        if (charCount < n * n) {
            cout << "R";
            for (int iii = charCount % n + 1; iii < n; iii++) {
                cout << "L";
            }
            cout << endl;
        }
    } else {
        cout << "NO\n";
    }
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
