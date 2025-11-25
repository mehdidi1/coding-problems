#include <bits/stdc++.h>
#include <pthread.h>
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

void solve() {
    ll n, k, q;
    cin >> n >> k >> q;
    vector<ll> a(n);
    vector<vector<int>> c(k);
    for (int iii = 0; iii < q; iii++) {
        vector<int> temp(3);
        cin >> temp[0] >> temp[1] >> temp[2];
        temp[1]--;
        temp[2]--;
        c[iii] = temp;
    }
    vector<bool> app1(n);
    vector<bool> app2(n);
    for (int iii = 0; iii < q; iii++) {
        for (int jjj = c[iii][1]; jjj <= c[iii][2]; jjj++) {
            if (c[iii][0] == 1) {
                app1[jjj] = true;
            } else {
                app2[jjj] = true;
            }
        }
    }
    for (int iii = 0; iii < n; iii++) {
        if (app1[iii] && app2[iii]) {
            a[iii] = k + 1;
        }
    }
    for (int iii = 0; iii < q; iii++) {
        int temp{0};
        for (int jjj = c[iii][1]; jjj <= c[iii][2]; jjj++) {
            if (c[iii][0] == 1 && a[jjj] == 0) {
                a[jjj] = k;
            } else {
                if (a[jjj] == 0) {
                    a[jjj] = temp;
                    temp++;
                    if (temp == k) {
                        temp++;
                    }
                }
            }
        }
    }
    print_arr(a);
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
