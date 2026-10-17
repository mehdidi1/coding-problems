#include <bits/stdc++.h>
#include <queue>
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
template <typename T> T mod(T x, T n);

void solve() {
    ll x, n;
    cin >> x >> n;
    set<int> positions;
    multiset<int> sizes;
    positions.emplace(0);
    positions.emplace(x);
    sizes.emplace(x);
    for (int iii = 0; iii < n; iii++) {
        int pos;
        cin >> pos;
        int low = *(--positions.lower_bound(pos));
        int upper = *positions.upper_bound(pos);
        sizes.erase(sizes.find(upper-low));
        positions.emplace(pos);
        sizes.emplace(upper-pos);
        sizes.emplace(pos-low);
        cout << *--sizes.lower_bound(x) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    /* cin >> t; */
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
template <typename T> T mod(T x, T n) { return ((x % n) + n) % n; }
