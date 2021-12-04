#include <bits/stdc++.h>
using namespace std;
const int mm = 100000 + 5;
vector<int> adj[mm];
bool vis[mm];
void dfs(int v) {
    vis[v] = 1;
    for (int u : adj[v]) {
        if (!vis[u]) {
            dfs(u);
        }
    }
}
void solve() {
    memset(vis, 0, sizeof vis);
    int n, box; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> box;
        adj[box].push_back(i);
        adj[i].push_back(box);
    }
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            count++;
        }
    }
    cout << count << ' ';
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
    }
}
int main()
{
    for (int i = 1; i <= 2; i++) {
        solve();
    }
}
//revisited this becuase its cool :3