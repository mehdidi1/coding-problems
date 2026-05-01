#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
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
    vi pair;
    vi impair;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (temp % 2 == 0) {
            pair.push_back(temp);
        } else {
            impair.push_back(temp);
        }
    }

    sort(pair.begin(), pair.end(), std::greater<int>());
    sort(impair.begin(), impair.end(), std::greater<int>());
    ll result{};
    if (impair.size() == 0) {
        for (int iii = 0; iii < n; iii++) {
            cout << "0 ";
        }
        cout << endl;
        return;
    }
    if (pair.size() == 0) {
        for (int iii = 1; iii <= n; iii++) {
            if (iii % 2 == 0) {
                cout << "0 ";
            } else {
                cout << impair[0] << " ";
            }
        }
        cout << endl;
        return;
    }
    result = impair[0];
    int step = 1;
    cout << result << " ";
    for (int iii = 0; iii < pair.size(); iii++) {
        result += pair[iii];
        cout << result << " ";
        step++;
    }

    ll maxResult{result};

    while (step < n) {
        if (impair.size() % 2 == 0 && step == n - 1) {
            cout << "0 ";
            step++;
        } else {

            if (result == maxResult) {
                result = maxResult - pair[pair.size() - 1];
            } else {
                result = maxResult;
            }

            cout << result << " ";
        }
        step++;
    }
    cout << endl;
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
