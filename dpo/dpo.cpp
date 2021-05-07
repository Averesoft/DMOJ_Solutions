//memoize is the bestoize 😫 (im gonna keep doing this everytime i find a memoizing problem)
#include <bits/stdc++.h>
using namespace std;
const int mm = 21 + 1, mod = 1e9 + 7;
int n, dp[mm][1 << mm];
bool a[mm][mm];
int mem(int i, int mask) {
    if (dp[i][mask] != -1) {
        return dp[i][mask];
    }
    if (i == n) {
        return 1;
    }
    dp[i][mask] = 0;
    for (int j = 0; j < n; j++) {
        if (((mask >> j ) & 1) == 0 && a[i][j]) {
            dp[i][mask] += mem(i + 1, mask | (1 << j)); dp[i][mask] %= mod;
        }
    }
    return dp[i][mask];
}
int main() {
    memset(dp, -1, sizeof (dp));
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    cout << mem(0, 0); 
}