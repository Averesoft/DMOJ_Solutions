#include <bits/stdc++.h>
using namespace std;
const int mm = 1e5+5;
typedef long long ll;
typedef pair<int, int> pi;
int N, M, Q, pre[mm], rt; vector<pi> adj [mm]; ll dis [mm], D, R, ans; bool vis [mm]; vector<ll> vec;
void dfs(int u, int pa, ll d){
    vis[u] = true; pre[u] = pa; dis[u] = d;
    if(d > D) { 
        D = d; rt = u;
    }
    for(auto & e : adj[u]) {
        if(e.first != pa) {
            dfs(e.first, u, d + e.second);
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> Q;
    for(int i = 1, u, v, w; i <= M; i++) {
        cin >> u >> v >> w; adj[u].push_back({v, w}); adj[v].push_back({u, w});
    }
    for(int i = 1; i <= N; i++) {
        if(vis[i]) {
            continue;
        }
        D = -1; dfs(i, 0, 0); D = -1; dfs(rt, 0, 0);
        if(Q == 1) { 
            ans += D + 1; continue;
        }
        R = 1e12;
        for(int u = rt; u != 0; u = pre[u]) {
            R = min(R, max(dis[u], D - dis[u]));
        }
        vec.push_back(R);
    }
    if(Q == 1) { 
        cout << ans - 1 << endl; 
    }
    else {
        sort(vec.begin(), vec.end(), greater<ll>());
        if(vec.size() > 1 && vec[0] == vec[1]) {
            cout << vec[0] + 1 << endl;
        }
        else {
            cout << vec[0] << endl;
        }
    }
}