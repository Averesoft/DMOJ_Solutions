#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int MM = 1e5 + 5, LOG = 17;
int N, dep[MM], lca[LOG][MM], dif[MM], ans; vector<int> adj[MM], val[MM]; map<pi, int> mp;
inline void ins(int x, int y, int id){
    if (x > y) {
        swap(x, y);
    }
    if (!mp.count({x, y})) {
        mp[{x, y}] = id;
    }
    else { 
        adj[id].push_back(mp[{x, y}]); adj[mp[{x,y}]].push_back(id); 
    }
}
int LCA(int u, int v) {
    if (dep[u] < dep[v]) {
        swap(u, v);
    }
    for(int i = LOG - 1; i >= 0; i--) {
        if (dep[lca[i][u]] >= dep[v]) {
            u = lca[i][u];
        }
    }
    if (u == v) return u;
    for(int i = LOG - 1; i >=0 ; i--) {
        if (lca[i][u] != lca[i][v]) {
            u = lca[i][u], v = lca[i][v];
        }
    }
    return lca[0][u];
}
void dfs(int u, int pa) {
    lca[0][u] = pa; dep[u] = dep[pa] + 1;
    for(int i = 1; i < LOG; i++) {
        lca[i][u] = lca[i-1][lca[i-1][u]];
    }
    for(int v: adj[u]) {
        if(v != pa) dfs(v, u);
    }
}
void dfs2(int u, int pa) {
    for(int v : adj[u]) {
        if(v != pa) { 
            dfs2(v, u);  dif[u] += dif[v]; 
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1, x, y, z, d; i<=N-2; i++) {
        cin >> x >> y >> z >> d; val[d].push_back(i);
        ins(x, y, i); ins(x, z, i); ins(y, z, i);
    }
    dfs(1, 0);
    for(int color = 1; color <= N; color++) {
        for(int j = 1; j < val[color].size(); j++) {
            int u = val[color][j-1], v = val[color][j], rt = LCA(u, v);
            dif[u]++; dif[v]++; dif[rt] -= 2;
        }
    }
    dfs2(1, 0);
    for(int i = 2; i <= N-2; i++) {
        ans += dif[i] == 0;
    }
    cout << ans << endl;
}