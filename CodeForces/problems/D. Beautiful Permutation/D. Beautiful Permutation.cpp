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
    int l, r;

    // search for l
    int m;
    int low = 0;
    int high = n - 1;
    while (high - low >= 1) {
        m = (high - low) / 2;
        cout << "1 " << low << "  " << m << endl;
        int sum1;
        cin >> sum1;
        cout << "2 " << low << "  " << m << endl;
        int sum2;
        cin >> sum2;
        if (sum1 != sum2) {
            high = m;
        } else {
            low = m;
        }
    }
    l = low;
    low = 0;
    high = n - 1;
    while (high - low >= 1) {
        m = (high - low) / 2;
        cout << "1 " << low << "  " << m << endl;
        int sum1;
        cin >> sum1;
        cout << "2 " << low << "  " << m << endl;
        int sum2;
        cin >> sum2;
        if (sum1 != sum2) {
            low = m;
        } else {
            high = m;
        }
    }
    r = high;
    cout << "! " << l << " " << r << endl;
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
