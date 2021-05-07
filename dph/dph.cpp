#include <bits/stdc++.h>
using namespace std;
const int mm = 1000 + 5, mod = 1e9 + 7;
int h, w, dp[mm][mm];
bool grid[mm][mm];
int main() {
    cin >> h >> w;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            char ch; cin >> ch;
            grid[i][j] = (ch == '.' ? 1 : 0);
        }
    }
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (!grid[i][j]) {
                dp[i][j] = 0;
            } else if (i == 1 && j == 1) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; dp[i][j] %= mod;
            }
        }
    }
    cout << dp[h][w];
}