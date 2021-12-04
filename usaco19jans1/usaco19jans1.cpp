#include <bits/stdc++.h>
using namespace std;
const int mm = 1e5 + 5;
int N, fre[mm], dis[mm];
bool vis[mm];
vector<int> adj[mm];
void dfs(int v, int pre) {
    dis[v] = dis[pre] + 1;
    for (int u : adj[v]) {
        if (!vis[u]) {
            vis[u] = 1;
            dfs(u, v);
        }
    }
}
int main() {
    cin >> N;
    for (int i = 1, a, b; i < N; i++) {
        cin >> a >> b; 
        adj[a].push_back(b); adj[b].push_back(a); fre[a]++; fre[b]++;
    }
    for (int i = 1; i <= N; i++) {
        if (fre[i] == 1) {
            int ans = 0;
            vis[i] = 1; dis[0] = -1; dfs(i, 0);
            for (int j = 1; j <= N; j++) {
                if (i == j) continue;
                if ((dis[j] - 1) % 2 != 0) {
                    ans++;
                }
            }
            cout << N - ans << '\n';
            return 0;
        }
    }
}