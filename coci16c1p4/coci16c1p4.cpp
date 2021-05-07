/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mm = 1e6 + 5;
struct frac {
    ll x, y;
    frac(ll x0, ll y0) { x = x0 / __gcd(x0, y0); y = y0 / __gcd(x0, y0); }
    bool operator < (const frac &a) const { x * a.y < a.x * y; }
};
int N, dis[mm], a[mm], mx[mm], mx2[mm], ch[mm]; vector<int> adj[mm]; frac ans(1e18, 1);
void dfs1(int u, int pa) {
    if (a[u] == 1) dis[u] = 1;
    for (int v : adj[u]) {
        if (v == pa) continue;
        dfs1(v, u);
        if (a[u] != 1) continue;
        if (dis[v] + 1 > mx[u]) { mx2[u] = mx[u]; mx[u] = dis[v] + 1; ch[u] = v; }
        else if (dis[v]  + 1> mx2[u]) mx2[u] = dis[v] + 1;
    }
    if (a[u] == 1) dis[u] = mx[u];
}
void dfs2(int u, int pa, int up) {
    ans = min(ans, frac{a[u], mx[u] + 1 + mx2[u]});
    ans = min(ans, frac{a[u], mx[u] + 1 + up});
    for (int v : adj[u]) {
        if (v == pa) continue;
        int tmp = 0;
        if (v == ch[u]) {
            if (a[u] == 1) tmp = max(up, mx2[u] + 1);
            dfs2(v, u, tmp);
        } else {
            if (a[u] == 1) tmp = max(up, mx[u] + 1);
            dfs2(v, u, tmp);
        }
    }
}
int main() {
    cin >> N;
    for (int i = 1, u, v; i < N; i++) {
        cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);
    }
    for (int i = 1; i <= N; i++) {
        cin >> a[i]; ans = min(ans, frac(a[i], 1));
    }
    dfs1(1, 0); dfs2(1, 0, 0);
    cout << ans.x << '/' << ans.y;
}
*/