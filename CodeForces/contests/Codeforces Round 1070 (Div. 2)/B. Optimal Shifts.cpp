#include <bits/stdc++.h>
#include <charconv>
#include <set>
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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll result{};
    ll nb1{};
    vi pos;
    for (int iii = 0; iii < n; iii++) {
        if (s[iii] == '1') {
            if (s[(iii + 1) % n] == '0') {
                pos.push_back(iii);
            }
            nb1++;
        }
    }
    while (nb1 < n) {
        for (int iii = 0; iii < pos.size(); iii++) {
            if (s[pos[iii]] == '1' && s[(pos[iii] + 1) % n] == '0') {
                nb1++;
                pos[iii] = (pos[iii] + 1) % n;
                s[pos[iii]] = '1';
            }
        }
        result++;
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

template <typename T> void print_arr(const vector<T> &arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i];
        if (i + 1 < arr.size())
            cout << " ";
    }
    cout << endl;
}
