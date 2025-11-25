#include <bits/stdc++.h>
#include <numeric>
using namespace std;

// ===================== Macros & Typedefs =====================
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

// ===================== Print Helper =====================
// Prints vector/array contents to cout
template <typename T>
void print_arr(const vector<T> &arr, const string &label = "") {
    if (!label.empty())
        cout << label << " = ";
    cout << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i];
        if (i + 1 < arr.size())
            cout << ", ";
    }
    cout << "]\n";
}

// ===================== Solve Function =====================
void solve() {
    ll n;
    cin >> n;
    vi a(n);
    vi b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    int nbPair = 0;
    for (int iii = 0; iii < n; iii++) {
        for (int jjj = iii + 1; jjj < n; jjj++) {
            int temp = gcd(a[iii], a[jjj]);
            if (temp > 1) {
                cout << 0 << endl;
                return;
            }
        }
        if (a[iii] % 2 == 0) {
            nbPair = 1;
        }
    }
    if (nbPair) {
        cout << nbPair << endl;
    } else
        cout << 2 << endl;
}

// ===================== Main =====================
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
