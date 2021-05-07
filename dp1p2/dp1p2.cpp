#include <bits/stdc++.h>
using namespace std;
const int mm = 1000 + 5;
int n, coins[mm], dp[mm][mm];
int mem(int l, int r) {
    if (dp[l][r] == -1) {
        if (l == r) {
            dp[l][r] = coins[r] - coins[l - 1];
        } else {
            dp[l][r] = coins[r] - coins[l - 1] - min(mem(l + 1, r), mem(l, r - 1));
        }
    }
    return dp[l][r];
}
int main() {
    memset(dp, -1, sizeof dp);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> coins[i]; coins[i] += coins[i - 1];
    }
    cout << mem(1, n);
}