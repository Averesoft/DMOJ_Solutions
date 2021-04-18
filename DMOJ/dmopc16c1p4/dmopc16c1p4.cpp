#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mm = 200000 + 5;
int n, val[mm], sz[mm]; ll dp[mm], pa[mm], len[mm], ans; vector<int> adj[mm];
void dfs1(int u, int p) {
    sz[u] = 1; dp[u] = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs1(v, u); sz[u] += sz[v]; dp[u] += dp[v] + sz[v];
    }
}
void dfs2(int u, int p) {
    len[u] = dp[u] * (n - sz[u] + 1) + pa[u] * sz[u];
    for (int v : adj[u]) {
        if (v == p) continue;
        len[u] += (sz[u] - sz[v] - 1) * (dp[v] + sz[v]);
        pa[v] = dp[u] - dp[v] - sz[v] + pa[u] + n - sz[v];
        dfs2(v, u);
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);
    }
    dfs1(1, 0); dfs2(1, 0);
    for (int i = 1; i <= n; i++) ans += val[i] * len[i];
    cout << ans;
}