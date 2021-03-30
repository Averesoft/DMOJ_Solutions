#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mm = 2 * 1e5 + 5, mod = 1000000000 + 7;
int n, m, k;
vector<int> adj[mm];
int dis1[mm], dis2[mm];
int distances[mm];
void bfs1() {
    memset(dis1, -1, sizeof dis1);
    queue<int> q;
    q.push(1); dis1[1] = 0;
    while(!q.empty()) {
        int node = q.front(); q.pop();
        for (int u : adj[node]) {
            if (dis1[u] == -1) {
                dis1[u] = dis1[node] + 1;
                q.push(u);
            }
        }
    }
}
void bfs2() {
    memset(dis2, -1, sizeof dis2);
    queue<int> q;
    q.push(n); dis2[n] = 0;
    while(!q.empty()) {
        int node = q.front(); q.pop();
        for (int u : adj[node]) {
            if (dis2[u] == -1) {
                dis2[u] = dis2[node] + 1;
                q.push(u);
            }
        }
    }
}
int main() {
    cin >> n >> m >> k;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b; adj[a].push_back(b); adj[b].push_back(a);
    }
    bfs1(); bfs2();
    ll sum = 0;
    for (int i = 2; i < n; i++) {
        if (dis1[i] != -1 && dis2[i] != -1 && dis1[i] <= k && dis2[i] <= k) {
            sum++; sum %= mod;
        }
    }
    ll power = 1;
    for (int i = 1; i <= sum; i++) {
        power *= 2; power %= mod;
    }
    cout << power;
}