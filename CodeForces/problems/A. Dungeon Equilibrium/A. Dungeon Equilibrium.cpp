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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    set<int> done;
    map<int, int> m;
    ll result{};
    for (int iii = 0; iii < n; iii++) {
        if (done.find(a[iii]) == done.end()) {
            if (m.find(a[iii]) == m.end()) {
                if (a[iii] == 1) {
                    done.insert(1);
                } else {
                    m.insert({a[iii], a[iii] - 1});
                }
            } else {
                m[a[iii]]--;
                if (m[a[iii]] == 0) {
                    m.erase(m.find(a[iii]));
                    done.insert(a[iii]);
                }
            }
        } else {
            result++;
        }
    }
    for (auto [key, value] : m) {
        result += key - value;
    }
    std::cout << result << endl;
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
