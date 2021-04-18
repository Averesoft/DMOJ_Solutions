#include <bits/stdc++.h>
using namespace std;
const int mm = 100000;
vector<int> edges[mm + 5];
bool vis[mm + 5];
void dfs(int v) {
    vis[v] = true;
    for (int u : edges[v]) {
        if (!vis[u]) {
            dfs(u);
        }
    }
}
void solve() {
    memset(vis, false, sizeof vis);
    int n, box; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> box;
        edges[box].push_back(i);
        edges[i].push_back(box);
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
        edges[i].clear();
    }
}
int main()
{
    for (int i = 0; i < 2; i++) {
        solve();
    }
}