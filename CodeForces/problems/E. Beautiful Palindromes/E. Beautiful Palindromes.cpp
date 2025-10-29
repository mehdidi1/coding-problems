#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> a, int k) {
    for (int i = 0; i < k; i++) {
        set<int> s = {1, 2, 3};
        s.erase(a[a.size() - 1]);
        int idx = a.size() - 2;
        while (idx >= 0 && a[idx] == a[a.size() - 1]) {
            idx--;
        }
        if (idx >= 0)
            s.erase(a[idx]);
        a.emplace_back(*s.begin());
        cout << *s.begin() << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    int f = 1; // test case counter
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        // Debug failing test
        if (f == 53) { // replace 53 with the failing test index
            cerr << "Failing test case 53 input:\n";
            cerr << n << " " << k << "\n";
            for (int x : a)
                cerr << x << " ";
            cerr << "\n";
        }

        solve(a, k);
        f++;
    }

    return 0;
}
