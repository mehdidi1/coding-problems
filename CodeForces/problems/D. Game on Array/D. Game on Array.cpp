#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<ll, ll> occ;
    for (int iii = 0; iii < n; iii++) {
        occ[a[iii]]++;
    }
    ll scoreA{0};
    ll scoreB{0};
    vll temp;
    for (auto [key, value] : occ) {
        if (key % 2 == 0) {
            scoreA += key * value / 2;
            scoreB += key * value / 2;
        } else {
            temp.push_back(value);
            scoreA += (key / 2) * (value);
            scoreB += (key / 2) * (value);
        }
    }
    sort(temp.begin(), temp.end(), std::greater<>());
    for (int iii = 0; iii < temp.size(); iii += 2) {
        scoreA += temp[iii];
        if (iii + 1 < temp.size())
            scoreB += temp[iii + 1];
    }
    cout << scoreA << " " << scoreB << endl;
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
