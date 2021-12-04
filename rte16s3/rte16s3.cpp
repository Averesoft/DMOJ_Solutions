#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int mm = 6000 + 5;
int N, Q, dis[mm];
vector<pii> adj[mm];
int main() {
    cin >> N;
    for (int i = 1, a, b, w; i <= N - 1; i++) {
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }
    cin >> Q;
    for (int i = 1, u, v; i <= Q; i++) {
        cin >> u >> v;
        memset(dis, 0, sizeof (dis));
        queue<int> q; q.push(u);
        while(!q.empty()) {
            int node = q.front(); q.pop();
            for (pii u : adj[node]) {
                dis[u.first] = dis[node] + u.second;  
                q.push(u.first);              
            }
        }
        cout << dis[v] << '\n';
    }
}