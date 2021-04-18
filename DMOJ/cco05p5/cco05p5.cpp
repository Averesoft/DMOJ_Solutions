#include <bits/stdc++.h>
using namespace std;
const int mm = 200000 + 5, inf = 0x3f3f3f3f;
int n, l[mm], r[mm], dp[mm][2];
int main() {
    cin >> n;
    l[0] = r[0] = 0;
    l[n + 1] = r[n + 1] = n - 1;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
    }
    dp[0][0] = dp[0][1] = 0;
    for (int i = 1; i <= n + 1; i++) {
        dp[i][0] = dp[i][1] = inf;
        dp[i][0] = min(dp[i][0], dp[i - 1][0] + abs(l[i - 1] - r[i]) + abs(r[i] - l[i]) + 1);
        dp[i][0] = min(dp[i][0], dp[i - 1][1] + abs(r[i - 1] - r[i]) + abs(r[i] - l[i]) + 1);
        dp[i][1] = min(dp[i][1], dp[i - 1][0] + abs(l[i - 1] - l[i]) + abs(l[i] - r[i]) + 1);
        dp[i][1] = min(dp[i][1], dp[i - 1][1] + abs(r[i - 1] - l[i]) + abs(l[i] - r[i]) + 1);
    }
    cout << dp[n + 1][0] - 2;
}