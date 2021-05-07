#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mm = 2000 + 5;
ll n, l, p[mm], dp[mm][mm][2];
int main() {
    cin >> n >> l;
    for (ll i = 1; i <= n; i++) {
        cin >> p[i];
    }
    sort(p + 1, p + n + 1);
    for (ll i = 1; i <= n; i++) {
        dp[i][i][0] = abs(p[i] - l) * n;
        dp[i][i][1] = abs(p[i] - l) * n;
    }
    for (ll i = 2; i <= n; i++) {
        for (ll j = 1; j <= n - i + 1; j++) {
            dp[j][i + j - 1][0] = min(dp[j + 1][i + j - 1][0] + (p[j + 1]-p[j]) * (n - i + 1), dp[j + 1][i + j - 1][1] + (p[i + j - 1] - p[j]) * (n - i + 1));
            dp[j][i + j - 1][1] = min(dp[j][i + j - 2][1] + (p[i + j - 1] - p[i + j - 2]) * (n - i + 1), dp[j][i + j - 2][0] + (p[i + j - 1] - p[j]) * (n - i + 1));
        }
    }
    cout << min(dp[1][n][0], dp[1][n][1]);
}