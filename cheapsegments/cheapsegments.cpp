#include <bits/stdc++.h>
using namespace std;
const int mm = 1e5 + 5, LOG = 17;
struct endpoint {
    int x, id, f;
};
int N, Q, lft[mm], rit[mm], val[mm], dep[mm], anc[LOG][mm], best[mm]; vector<endpoint> p; vector<int> adj[mm];
void dfs(int u, int pa) {
    anc[0][u] = pa;
    if (u > 0) {
        best[u] = (val[u] <= val[best[pa]]) ? u : best[pa];
    }
    for (int k = 1; k < LOG; k++) {
        anc[k][u] = anc[k - 1][anc[k - 1][u]];
    }
    for (int v : adj[u]) {
        if (v == pa) continue;
        dep[v] = dep[u] + 1; dfs(v, u);
    }
}
int LCA(int u, int v) {
    if (dep[u] < dep[v]) {
        swap(u, v);
    }
    for (int k = LOG - 1; k >= 1; k--) {
        if (anc[k][u] != -1 && dep[anc[k][u]] >= dep[v]) {
            u = anc[k][u];
        }
    }
    if (u == v) {
        return anc[0][v];
    }
    for (int k = LOG - 1; k >= 1; k--) {
        if (anc[k][u] != -1 && anc[k][v] != -1 && anc[k][u] != anc[k][v]) {
            u = anc[k][u], v = anc[k][v];
        }
    }
    return anc[0][u];
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N; memset(anc, -1, sizeof (anc));
    for (int i = 1;  i <= N; i++) {
        cin >> lft[i] >> rit[i] >> val[i];
        p.push_back({lft[i], i, 0});
        p.push_back({rit[i], i, 1});
    }
    sort(p.begin(), p.end(), [](endpoint &a, endpoint &b) { return a.x < b.x;});
    stack<int> stk; stk.push(0);
    for (auto e : p) {
        if (e.f == 0) {
            adj[stk.top()].push_back(e.id); stk.push(e.id);
        } else {
            stk.pop();
        }
    }
    val[0] = 1e9; dfs(0, -1); cin >> Q;
    for (int i = 1, u, v; i <= Q; i++) {
        cin >> u >> v; int rt = LCA(u, v);
        cout << (rt == 0 ? -1 : best[rt]) << '\n';
    }
}