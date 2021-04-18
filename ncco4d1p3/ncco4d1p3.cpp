#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define INFINITY 0x3f3f3f3f
const int mm = 5000 + 5;
int n, m;
vector<pii> adj[mm];
pii dis[mm];
bool vis[mm];
int main()
{
    memset(vis, false, sizeof vis);
    memset(dis, INFINITY, sizeof dis);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        adj[a].push_back({ b, w });
        adj[b].push_back({ a, w });
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dis[1] = { 0, INFINITY }; pq.push({ 0, 1 });
    while (!pq.empty()) {
        pii node = pq.top(); pq.pop();
        for (pii u : adj[node.second]) {
            if (node.first + u.second < dis[u.first].first) {
                dis[u.first].second = dis[u.first].first;
                dis[u.first].first = node.first + u.second;
                pq.push({ dis[u.first].first, u.first });
            }
            else if (dis[u.first].first < node.first + u.second && node.first + u.second < dis[u.first].second) {
                dis[u.first].second = node.first + u.second;
                pq.push({ dis[u.first].second, u.first });
            }
        }
    }
    cout << dis[n].second << '\n';
}