#include <algorithm>
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
    int n, m;
    cin >> n >> m;
    int mini = min(n, m);
    string pattern;
    char endPat;
    if (mini == n) {
        pattern = "GB";
        endPat = 'G';
    } else {
        pattern = "BG";
        endPat = 'B';
    }
    for (int iii = 0; iii < mini; iii++) {
        cout << pattern;
    }
    for (int iii = mini; iii < max(n, m); iii++) {
        cout << endPat;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
