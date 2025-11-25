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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<int>> adj(n + 1);

    for (int iii = 0; iii < m; iii++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    set<int> notSeen;
    for (int iii = 1; iii < n + 1; iii++) {
        notSeen.insert(iii);
    }

    ll result{};
    set<int> visited;
    queue<int> q;
    q.push(1);
    q.push(-1);
    visited.insert(1);
    if (notSeen.find(a[0]) != notSeen.end())
        notSeen.erase(notSeen.find(a[0]));
    while (!q.empty() && notSeen.size() > 0) {
        if (q.front() == -1) {
            result++;
            q.pop();
            if (!q.empty()) {
                q.push(-1);
            }
            continue;
        }
        for (int node : adj[q.front()]) {
            if (visited.find(node) == visited.end()) {
                visited.insert(node);
                q.push(node);
                if (notSeen.count(a[node - 1])) {
                    notSeen.erase(a[node - 1]);

                    // --- CRITICAL FIX: Early Exit Check ---
                    if (notSeen.empty()) {
                        // The distance to this node is result + 1
                        cout << result + 1 << endl;
                        return;
                    }
                }
            }
        }
        q.pop();
    }

    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
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
