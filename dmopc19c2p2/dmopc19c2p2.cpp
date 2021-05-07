#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
const int mm = 500 + 5;
int n, m, a[mm][mm], dp[mm][mm];
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < mm; i++) {
        for (int j = 0; j < mm; j++) {
            dp[i][j] = inf;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = a[i][j];
            } else if (i == 0) {
                dp[i][j] = dp[i][j - 1] + a[i][j];
            } else if (j == 0) {
                dp[i][j] = dp[i - 1][j] + a[i][j];
            } else {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[i][j]);
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + a[i][j]);
            }
        }
    }
    cout << dp[n - 1][m - 1];
}