#include <bits/stdc++.h>
#include <iostream>

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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

int main() {
    string S, T;
    std::cin >> S >> T;
    std::vector<char> freqS(26);
    std::vector<char> freqT(26);
    int nbS{0};
    int nbT{0};
    int nbJokr{0};
    for (int iii = 0; iii < S.size(); iii++) {
        if (S[iii] == '@') {
            nbS++;
        } else {
            freqS[S[iii]]++;
        }
        if (T[iii] == '@') {
            nbT++;
        } else {
            freqS[T[iii]]++;
        }
    }
    for (int iii = 0; iii < 26; iii++) {
        int temp = freqS[iii] - freqT[iii];
        if (freqS[iii] - freqT[iii] > 0) {
            nbT = nbT - freqS[iii] - freqT[iii];
        }
        else if (temp < 0){
            nbS = nbS + temp;
        }
    }
    if (nbS < 0 || nbT < 0){
        cout << "No";
    }
    else {
        cout << "Yes";
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
