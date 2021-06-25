#include <bits/stdc++.h>
using namespace std;
const int mm = 1000 + 5;
int n; 
bool vis[mm], adj[mm][mm];
vector<int> dfs(int u) {
    vector<int> vc;
    for (int v = 1; v <= n; v++) {
        if (!vis[v] && adj[u][v]) {
            vis[v] = 1; vector<int> temp = dfs(v);
            for (int j : temp) {
                vc.push_back(j);
            }
        }
    }
    vc.push_back(u);
    return vc;
}
int main() {
    memset(vis, 0, sizeof (vis));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> adj[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            vector<int> vc = dfs(i);
            sort(vc.begin(), vc.end());
            for (int i = 0; i < vc.size(); i++) {
                cout << vc[i] << ' ';
            }
            cout << '\n';
        }
    }
}