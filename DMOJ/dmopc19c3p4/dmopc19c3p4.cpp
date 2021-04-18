#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mm = 3e5 + 5, mod = 1e9 + 7;
int n, val[mm]; ll dp[mm], ans; 
vector<int> adj[mm]; char s[mm];
void dfs(int u, int pa, int color) {
    ll sum = 0, join = 0;
    for (int v : adj[u]) {
        if (v == pa) continue;
        dfs(v, u, color);
        join = (join + (sum + join) * dp[v]) % mod;
        sum = (sum + dp[v]) % mod;
    }
    if (val[u] == color) {
        dp[u] = (1 + sum + join) % mod;
        ans = (ans + dp[u]) % mod;
    } else {
        ans = (ans + join) % mod;
        dp[u] = (sum + join) % mod;
    }
}
int main() {
    scanf("%d %s", &n, s + 1);
    for (int i = 1; i <= n; i++) val[i] = s[i] == 'R';
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v); adj[v].push_back(u);
    }
    dfs(1, 0, 1); dfs(1, 0, 0);
    cout << ans;
}