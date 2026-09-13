

#include <iostream>
int main(int argc, char *argv[]) {
    int n;
    std::cin >> n;
    char grid[n][n];
    for (int iii = 0; iii < n; iii++) {
        for (int jjj = 0; jjj < n; jjj++) {
            std::cin >> grid[iii][jjj];
        }
    }

    long long dp[n][n];
    if (grid[0][0] == '*' || grid[n - 1][n - 1] == '*') {
        std::cout << 0;
        return 0;
    }
    
    for (int iii = 0; iii < n; iii++) {
        for (int jjj = 0; jjj < n; jjj++) {
            if (iii==0 && jjj==0){
                dp[iii][jjj] = 1;
                continue;
            }
            if (grid[iii][jjj]=='*'){
                dp[iii][jjj] = 0;
                continue;
            }
            long long uppercase,lowercase;
            if (iii-1 < 0){
                uppercase = 0;
            }
            else if (grid[iii-1][jjj] == '*'){
                uppercase = 0;
            }
            else {
                uppercase = dp[iii-1][jjj];
            }
            if (jjj-1 < 0){
                lowercase = 0;
            }
            else if (grid[iii][jjj-1] == '*'){
                lowercase = 0;
            }
            else {
                lowercase = dp[iii][jjj-1];
            }
            dp[iii][jjj] = lowercase+uppercase%(static_cast<long long>(1e9+7));
        }
    }

    std::cout << (dp[n-1][n-1]%(static_cast<long long>(1e9+7)));
    return 0;
}
