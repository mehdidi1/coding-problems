#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <vector>
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

class SegmentTree {
  public:
    SegmentTree(const vector<int> &data) {
        n = data.size();
        tree.resize(2 * n);
        for (int iii = 0; iii < n; iii++) {
            tree[n + iii] = data[iii];
        }
        for (int i = n - 1; i >= 0; i--) {
            tree[i] = min(tree[2 * i], tree[2 * i + 1]);
        }
    }

    int get_min_interval(int lower, int upper) {
        lower += n;
        upper += n;
        int curr = INT_MAX;
        while (lower < upper) {
            if ((lower & 1)) {
                curr = min(curr, tree[lower]);
                lower++;
            }
            if (upper & 1) {
                upper--;
                curr = min(curr, tree[upper]);
            }
            upper = upper / 2;
            lower = lower / 2;
        }
        return curr;
    }

    void update(int idx, int val) {
        int pos = n + idx;
        tree[pos] = val;
        for (pos /= 2; pos >= 1; pos /= 2) {
            tree[pos] = min(tree[2 * pos], tree[2 * pos + 1]);
        }
    }

  private:
    int n;
    vector<int> tree;
};

void solve() {
    ll n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    SegmentTree tree = SegmentTree(a);
    for (int iii = 0; iii < q; iii++) {
        int a,b,c;
        cin >> a >> b >> c;
        if (a == 1){
            tree.update(b-1, c);
        }
        else {
            std::cout << tree.get_min_interval(b-1,c) << endl;
        }
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
