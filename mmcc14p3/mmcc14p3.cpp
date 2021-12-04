#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int mm = 5 * 1e4 + 5;
int N, S, ans, pa[mm], dep[mm]; vector<pii> vc; vector<int> adj[mm]; bool vis[mm];
void dfs(int u) {
    vc.push_back({dep[u], u});
    for (int v : adj[u]) {
        if (v == pa[v]) continue;
        pa[v] = u; dep[v] = dep[u] + 1; dfs(v);
    }
}
void color (int u, int p, int len) {
    vis[u] = 1;
    if (len == 0) return;
    for (int v : adj[u]) {
        if (v != p) {
            color(v, u, len - 1);
        }
    }
}
bool check(int len) {
    int cnt = 0;
    memset(vis, 0, sizeof (vis));
    for (pii e : vc) {
        int u = e.second;
        if (vis[u]) continue;
        for (int k = 0; k < len; k++) {
            u = pa[u];
        }
        cnt++; color(u, 0, len);
    }
    return cnt <= S;    
}
int main() {
    cin >> N >> S;
    for (int i = 1, u, v; i < N; i++) {
        cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    if (S >= N) {
        cout << 0 << '\n'; return 0;
    }
    pa[1] = 1; dfs(1);
    sort(vc.begin(), vc.end(), greater<pii>());
    int lo = 1, hi = N;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            ans = mid; hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << ans << '\n';
}