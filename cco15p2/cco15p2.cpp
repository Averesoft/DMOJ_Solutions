#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mm = 18 + 5, inf = 0x3f3f3f3f;
ll n, m, dp[mm][1 << 18], adj[mm][mm], ans = INT_MIN;
ll mem(ll a, ll b) {
    b |= 1 << a;
    if (dp[a][b] != -1) return dp[a][b];
    if (a == 0) {
        return dp[a][b] = 0;
    } else {
        dp[a][b] = INT_MIN;
        for (ll i = 0; i < n; i++) {
            if (adj[i][a] != -1 && (b & (1 << i))) {
                dp[a][b] = max(dp[a][b], mem(i, b & ~(1 << a)) + adj[i][a]);
            }
        }
        return dp[a][b];
    }
}
int main() {
    cin >> n >> m;
    memset(adj, -1, sizeof (adj));
    memset(dp, -1, sizeof (dp));
    for (ll i = 0, s, d, l; i < m; i++) {
        cin >> s >> d >> l; adj[s][d] = l;
    }
    for (ll i = 0; i < (1 << (n - 1)); i++) {
        ans = max(ans, mem(n - 1, i));
    }
    cout << ans << '\n';
}