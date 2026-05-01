#include <bits/stdc++.h>
#include <map>
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
    string s, t;
    cin >> s >> t;
    map<char, ll> occ;
    for (char c : t) {
        occ[c]++;
    }
    for (char c : s) {
        occ[c]--;
    }
    string result;
    bool appended = false;
    for (char c = 'a'; c <= 'z'; c++) {
        if (c < s[0]) {
            while (occ[c] > 0) {
                result.push_back(c);
                occ[c]--;
            }
        } else if (c == s[0]) {
            int i = 1;
            while (i < s.size() && s[i] == c) {
                i++;
            }
            if (i < s.size() && !appended && s[i] < c) {
                result.append(s);
                appended = true;
            } else {
                while (occ[c] > 0) {
                    result.push_back(c);
                    occ[c]--;
                }
                if (!appended) {
                    result.append(s);
                    appended = true;
                }
            }
        } else if (!appended) {
            result.append(s);
            appended = true;
        } else {
            while (occ[c] > 0) {
                result.push_back(c);
                occ[c]--;
            }
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

template <typename T> void print_arr(const vector<T> &arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i];
        if (i + 1 < arr.size())
            cout << " ";
    }
    cout << endl;
}
