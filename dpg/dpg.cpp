#include <bits/stdc++.h>
using namespace std;
const int mm = 1e5 + 5;
int n, m, dis[mm], ma = -1;
bool vis[mm];
vector<int> adj[mm];
int dfs(int node) {
    vis[node] = true;
    if (adj[node].size() == 0) {
        dis[node] = 0;
    }
    for (int u : adj[node]) {
        if (!vis[u]) {
            dis[node] = max(dis[node], dfs(u) + 1);
        } else {
            dis[node] = max(dis[node], dis[u] + 1);
        }
    }
    return dis[node];
}
int main() {
    memset(dis, -1, sizeof dis);
    memset(vis, 0, sizeof vis);
    cin >> n >> m;
    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y; adj[x].push_back(y);
    }
    for (int i = 1; i <= n; i++){
        if (!vis[i]) {
            dfs(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        ma = max(ma, dis[i]);
    }
    cout << ma;
}