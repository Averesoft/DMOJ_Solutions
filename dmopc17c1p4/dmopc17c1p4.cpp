#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mm = 5000 + 5;
ll n, h, G[mm], H[mm], Q[mm], T[mm], dp[2][mm];
ll ans = 0;
bool vis[mm];
int main() {
    cin >> n >> h;
    for (ll i = 1; i <= n; i++) {
        cin >> G[i] >> H[i] >> Q[i] >> T[i];
    }
    for (ll i = 1; i <= n; i++) {
        ll x = i % 2, y = (i + 1) % 2;
        memset(vis, 0, sizeof vis);
        for (ll j = 0; j <= h; j++) {
            if (j >= H[i]) {
                dp[x][j] = dp[y][j-H[i]] + G[i];
                vis[j] = true;
            }
        }
        for (ll j = 0; j <= h; j++) {
            if (j >= T[i] && vis[j - T[i]]) {
                dp[x][j] = max(dp[x][j], dp[x][j - T[i]] + Q[i]);
            }
        }
        for (ll j = 0; j <= h; j++) {
            dp[x][j] = max(dp[x][j], dp[y][j]);
        }
    }
    for (ll i = 0; i <= h; i++) {
        ans = max(ans, dp[n % 2][i]);
    }
    cout << ans;
}