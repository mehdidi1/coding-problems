#include <bits/stdc++.h>
#include <cmath>
#include <ostream>
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

template <typename T> void print_arr(const vector<T> &arr);

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<long long>> a(n, vector<long long>(m));
    ll nbOnes{};
    vll rows(n);
    vll cols(m);

    for (int i = 0; i < n; i++) {
        for (int jjj = 0; jjj < m; jjj++) {
            cin >> a[i][jjj];
            if (a[i][jjj]) {
                rows[i]++;
                cols[jjj]++;
                nbOnes++;
            }
        }
    }
    cout << nbOnes / 2 * static_cast<int>(ceil(nbOnes / 2.0)) << std::endl;
    int i = 0;
    int j = 0;
    string result;
    while (i < n && j < m) {
        if (rows[i] <= cols[j]) {
            if (a[i][j]) {
                cols[j]--;
            }
            if (j + 1 < m)
                cols[j + 1] += cols[i];
            result.append("R");
            j++;
        } else {
            if (a[i][j]) {
                rows[i]--;
            }
            if (i + 1 < n)
                rows[i + 1] += rows[i];
            result.append("D");
            i++;
        }
    }
    while (j < m) {
        result.append("R");
        j++;
    }
    while (i < n) {
        result.append("D");
        i++;
    }
    cout << result << std::endl;
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

template <typename T> void print_arr(const vector<T> &arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i];
        if (i + 1 < arr.size())
            cout << " ";
    }
    cout << endl;
}
