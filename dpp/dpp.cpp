#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mm = 1e5 + 5, mod = 1e9 + 7;
int n; ll dp[mm][2]; vector<int> adj[mm];
void dfs(int u, int pa) {
    dp[u][0] = dp[u][1] = 1;
    for (int v : adj[u]) {
        if (v == pa) continue;
        dfs(v, u);
        dp[u][0] = dp[u][0] * (dp[v][0] + dp[v][1]) % mod;
        dp[u][1] = dp[u][1] * dp[v][0] % mod;
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        adj[x].push_back(y); adj[y].push_back(x);
    }
    dfs(1, 0);
    cout << (dp[1][0] + dp[1][1]) % mod << '\n';
}