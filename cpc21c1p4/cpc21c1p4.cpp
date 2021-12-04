#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const ll mm = 3 * 1e5 + 5;
ll N, M;
bool vis[mm];
vector<ll> adj[mm], rev[mm];
ll bfs(ll start) {
    ll ma = -1;
    memset(vis, 0, sizeof vis);
    queue<ll> q; q.push(start); vis[start] = 1;
    while(!q.empty()) {
        ll node = q.front(); q.pop();
        for (ll u : adj[node]) {
            if (!vis[u]) {
                if (u > start) {
                    ma = u;
                }
                vis[u] = 1; q.push(u);
            }
        }
    }
    return ma;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (ll i = 0, a, b; i < M; i++) {
        cin >> a >> b; adj[a].push_back(b); 
    }
    ll ma = -1, num = -1;
    for (ll x = 1; x <= N; x++) {
        ll temp = bfs(x);
        if (temp != -1) {
            ma = temp; num = x;
        }
    }
    if (num != -1) {
        cout << num << ' ' << ma;
    } else {
        cout << -1;
    }
}