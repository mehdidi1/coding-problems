#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
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

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<char>> path(n, vector<char>(m, ' '));
    vector<vector<char>> map(n, vector<char>(m, ' '));
    int start_x, start_y;
    int end_x, end_y;
    for (int iii = 0; iii < n; iii++) {
        for (int jjj = 0; jjj < m; jjj++) {
            cin >> map[iii][jjj];
            if (map[iii][jjj] == 'A') {
                start_x = iii;
                start_y = jjj;
            }
            if (map[iii][jjj] == 'B') {
                end_x = iii;
                end_y = jjj;
                map[iii][jjj] = '.';
            }
        }
    }
    std::queue<pair<int, int>> q;
    q.push({start_x, start_y});
    while (!q.empty()) {
        if (path[end_x][end_y] != ' ') {
            cout << "YES" << "\n";
            pair<int,int> curr = {end_x,end_y};
            string result {};
            while (curr.first != start_x || curr.second != start_y){
                result.push_back(path[curr.first][curr.second]);
                switch (path[curr.first][curr.second]) {
                    case 'R':
                        curr.second--;
                        break;
                    case 'L':
                        curr.second++;
                        break;
                    case 'U':
                        curr.first++;
                        break;
                    case 'D':
                        curr.first--;
                        break;
                    default:
                        
                        break;
                }
            }
            std::reverse(result.begin(), result.end());
            cout <<  result.size() << "\n";
            cout << result << "\n";
            return;
        }
        pii &next = q.front();
        if (next.first < n-1 && map[next.first + 1][next.second] == '.' && path[next.first+1][next.second] == ' ') {
            path[next.first + 1][next.second] = 'D';
            q.push({next.first + 1, next.second});
        }
        if (next.first > 0 && map[next.first - 1][next.second] == '.'&& path[next.first-1][next.second] == ' ') {
            path[next.first - 1][next.second] = 'U';
            q.push({next.first - 1, next.second});
        }
        if (next.second < m-1 && map[next.first][next.second + 1] == '.'&& path[next.first][next.second+1] == ' ') {
            path[next.first][next.second + 1] = 'R';
            q.push({next.first, next.second + 1});
        }
        if (next.second > 0 && map[next.first][next.second - 1] == '.'&& path[next.first][next.second-1] == ' ') {
            path[next.first][next.second - 1] = 'L';
            q.push({next.first, next.second - 1});
        }
        q.pop();
    }
    cout << "NO" << "\n";
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
