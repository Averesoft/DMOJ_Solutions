#include <bits/stdc++.h>
using namespace std;
const int mm = 1.5 * 1000 + 5;
int n, a[mm][mm], dp[mm][mm], ans;
int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int dfs(int r, int c) { 
    if (dp[r][c] != 0) return dp[r][c];
    dp[r][c] = 1; 
    for (int k = 0; k < 4; k++) {
        int nr = r + d[k][0], nc = c + d[k][1];
        if (nr < 0 || nr >= n || n < 0 || nc >= n || a[nr][nc] <= a[r][c]) continue;
        dp[r][c] = max(dp[r][c], dfs(nr, nc) + 1);
    }
    ans = max(ans, dp[r][c]);
    return dp[r][c];
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dfs(i, j);
        }
    }
    cout << ans - 1;
}