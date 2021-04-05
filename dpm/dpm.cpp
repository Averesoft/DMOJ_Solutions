#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mm = 100 + 5, mmm = 1e5 + 5, mod = 1e9 + 7;
ll n, k, a[mm], dp[mm][mmm];
int main() {
    cin >> n >> k;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i <= n; i++) {
        for (ll j = 0; j <= k; j++) {
            if (i == 0) {
                dp[i][j] = 0;
            } else if (i == 1) {
                if (j > a[1]) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = 1;
                }
            } else if (j == 0) {
                dp[i][j] = (dp[i - 1][j] + mod) % mod;
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                if (j - 1 - a[i] >= 0) {
                    dp[i][j] -= dp[i - 1][j - 1 - a[i]];
                }
                dp[i][j] += mod; dp[i][j] %= mod;
            }
        }
    }
    cout << dp[n][k];
}