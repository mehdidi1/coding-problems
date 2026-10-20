#include <bits/stdc++.h>
#include <utility>
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

int find(vi& dsu, int idx){
    if (dsu[idx]==idx){
        return idx;
    }
    else {
        dsu[idx] = find(dsu,dsu[idx]);
        return dsu[idx];
    }
}

bool unite(vi& dsu,vi& sizes, int a, int b){
    a = find(dsu,a);
    b = find(dsu,b);
    if (a!=b){
        if (sizes[a]<sizes[b]){
            std::swap(a, b);
        }
        dsu[b] = a;
        sizes[a] += sizes[b];
        return true;
    }
    return false;
}

void solve() {
    ll n,m;
    cin >> n >> m;
    vi dsu(n+1);
    vi sizes(n+1);
    for (int iii = 1; iii <= n; iii++) {
        dsu[iii] = iii;
        sizes[iii] = 1;
    }

    ll a,b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        unite(dsu,sizes,a,b);
    }
    int result = 0;
    string roads {};
    for (int iii = 2; iii <= n; iii++) {
       if (unite(dsu,sizes,iii-1,iii)) {
           result++;
           roads.append(std::to_string(iii-1));
           roads.append(" ");
           roads.append (std::to_string(iii));
           roads.append("\n");
       }
    }
    cout << result << "\n" << roads;

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
