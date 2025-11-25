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

template <typename T> void print_arr(const vector<T> &arr);

void solve() {
    string s;
    cin >> s;
    ll prefix{0};
    ll suffix{0};
    ll n = s.size();
    ll i = 0;
    bool starMiddle = false;
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    while (s[i] == '<' && i < n) {
        i++;
        prefix++;
    }
    if (i == n) {
        cout << prefix << endl;
        return;
    }
    if (s[i] == '*') {
        i++;
        starMiddle = true;
    }
    while (i < n && s[i] == '>') {
        i++;
        suffix++;
    }
    if (i == n) {
        if (starMiddle) {
            prefix++;
            suffix++;
        }
        cout << max(suffix, prefix) << endl;
    } else {
        cout << -1 << endl;
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

template <typename T> void print_arr(const vector<T> &arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i];
        if (i + 1 < arr.size())
            cout << " ";
    }
    cout << endl;
}
