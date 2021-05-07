//memoizing is the bestoizing 😫
#include <bits/stdc++.h>
using namespace std;
const int mm = 15 + 1, mod = 13371337;
int n, dp[mm][1 << mm];
bool a[mm][mm];
int mem(int i, int mask) {
    if (dp[i][mask] != -1) {
        return dp[i][mask];
    }
    if (!((1 << i) & mask)) {
        return dp[i][mask] = 0;
    } 
    if (i == 0 && mask == 1) {
        return dp[i][mask] = 1;
    }
    dp[i][mask] = 0;
    for (int j = 0; j < n; j++) {
        if (a[j][i] && ((1 << j) & mask)) {
            dp[i][mask] += mem(j, ~(1 << i) & mask); dp[i][mask] %= mod;
        }
    }
    return dp[i][mask];
}
void solve() {
    memset(dp, -1, sizeof (dp));
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int sum = 0;
    for (int i = 1 << (n - 1); i < 1 << n; i++) {
        sum += mem(n - 1, i); sum %= mod;
    }
    cout << sum << '\n';
}
int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}