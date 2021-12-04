#include <bits/stdc++.h>
using namespace std;
const int mm = 1e6 + 5;
int N, M, p, q, ans = 0;
vector<int> adj[mm];
bool vis[mm];
void dfs(int u) {
    for (int v : adj[u]) {
        if (!vis[v]) {
            vis[v] = 1; dfs(v);
        }
    }
}
int main() {
    cin >> N >> M;
    for (int i = 0, x, y; i < M; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
    }
    cin >> p >> q;
    vis[p] = 1; dfs(p);
    if (vis[q]) {
        ans = 1;
    }
    memset(vis, 0, sizeof (vis));
    vis[q] = 1; dfs(q);
    if (vis[p]) {
        ans = 2;
    }
    if (ans == 0) {
        cout << "unknown";
    } else if (ans == 1) {
        cout << "yes";
    } else if (ans == 2) {
        cout << "no";
    }
}