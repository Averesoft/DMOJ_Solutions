#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1e9 + 7, MM = 2e5+5;
int n, p[MM]; 
vector<pii> vec; 
vector<int> adj[MM]; ll val[MM], ans;
int recurs(int d){
    return (d==p[d] ? p[d]: p[d] = recurs(p[d]));
}
void dfs(int u, int pa, ll s){
    s += val[u]; ans = max(ans, s);
    for(int v: adj[u]) {
        if(v != pa) {
            dfs(v, u, s);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> val[i]; p[i] = i;
    }
    for(int i=1, u, v, w; i<n; i++){
        cin >> u >> v >> w;
        if(w > 1){
            int fu = recurs(u), fv = recurs(v);
            p[fu] = fv; val[fv] += val[fu];
        } else {
            vec.push_back({u, v}); 
        }
    }
    for(pii &e: vec){
        adj[recurs(e.first)].push_back(recurs(e.second));  
        adj[recurs(e.second)].push_back(recurs(e.first));
    }
    dfs(recurs(1), 0, 0);
    cout << ans << endl;
}