#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin >> t;
 
    while (t--) {
        int n;
        cin >> n;
 
        vector<int> vec(n); for (auto &x: vec) cin >> x;
        if (count(vec.begin(), vec.end(), 0) == 1) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        bool seen_zero = false;
        for (int i = 0; i < n; i++) {
            if (vec[i] != 0) cout << 'A';
            else if (seen_zero) cout << 'B';
            else {
                seen_zero = true;
                cout << 'C';
            }
        }
        cout << "\n";
    }
}
