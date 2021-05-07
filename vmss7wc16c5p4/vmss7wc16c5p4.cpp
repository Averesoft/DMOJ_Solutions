#include <bits/stdc++.h>
using namespace std;
const int mm = 1e5 + 5;
int n, x, y, z, dp[mm];
int main() {
    cin >> n;
    cin >> x >> y >> z;
    for (int i = 1; i <= n; i++) {
        dp[i] = -1;
        if (i - x >= 0 && dp[i - x] != -1) {
            dp[i] = max(dp[i], dp[i - x] + 1);
        }
        if (i - y >= 0 && dp[i - y] != -1) {
            dp[i] = max(dp[i], dp[i - y] + 1);
        }
        if (i - z >= 0 && dp[i - z] != -1) {
            dp[i] = max(dp[i], dp[i - z] + 1);
        }
    }
    cout << dp[n];
}