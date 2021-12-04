//this is just bfs
#include <bits/stdc++.h>
using namespace std;
const int mm = 1e6 + 5;
int N, M, dis[mm];
bool vis[mm];
vector<int> adj[mm];
queue<int> q;
int main() {
    cin >> N >> M;
    for (int i = 1, a, b; i <= M; i++) {
        cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    dis[1] = 0; q.push(1); vis[1] = 1;
    while(!q.empty()) {
        int v = q.front(); q.pop();
        for (int u : adj[v]) {
            dis[u] = dis[v] + 1;
            vis[u] = 1;
            q.push(u);
        }
    }
    int ma = -1;
    for (int i = 1; i <= N; i++) {
        ma = max(ma, dis[i]);
    }
    cout << ma;
}
/* mcpt btw not dmoj
 * https://www.mcpt.ca/problem/bfs
 * was helping jacob so i decided to code a solution myself
 * :3
 */