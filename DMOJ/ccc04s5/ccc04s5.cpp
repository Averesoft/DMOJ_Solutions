#include <bits/stdc++.h>
using namespace std;
const int mm = 100 + 5;
int m, n; 
int grid[mm][mm], dp[mm][mm];
int main() {
    while(1) {
        cin >> m >> n;
        if (m == 0 && n == 0) {
            return 0;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                char ch; cin >> ch;
                if (ch >= '1' && ch <= '9') {
                    grid[i][j] = ch - '0';
                } else if (ch == '*') {
                    grid[i][j] = -2;
                } else {
                    grid[i][j] = 0;
                }
                dp[i][j] = -1;
            }
        }
        dp[m][1] = grid[m][1];
        for (int i = m - 1; i >= 1; i--) {
            if (grid[i][1] == -2) {
                break;
            } else {
                if (grid[i][1] != 20) {
                    dp[i][1] = grid[i][1] + dp[i + 1][1];
                } else {
                    dp[i][1] = dp[i + 1][1];
                }
            }
        }
        for (int j = 2; j <= n; j++) {
            for (int i = 1; i <= m; i++) {
                if (dp[i][j - 1] != -1) {
                    int num = dp[i][j - 1];
                    for (int k = i; k <= m; k++) {
                        if (grid[k][j] == -2) {
                            break;
                        }
                        num += grid[k][j];
                        dp[k][j] = max(dp[k][j], num);
                    }
                }
            }
            for (int i = m; i >= 1; i--) {
                if (dp[i][j - 1] != -1) {
                    int num = dp[i][j - 1];
                    for (int k = i; k >= 1; k--) {
                        if (grid[k][j] == -2) {
                            break;
                        }
                        num += grid[k][j];
                        dp[k][j] = max(dp[k][j], num);
                    }
                }
            }
        }
        cout << dp[m][n] << '\n';
    }
    
}