#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;
const int MM  = 2e5+5;
int N, K, sz[MM], cnt[MM]; vector<pi> adj[MM]; ll ans =0;
void getsz(int u, int pa){
    sz[u] = cnt[u];
    for(pi e: adj[u]){
        int v = e.first;
        if(v != pa){ getsz(v, u);  sz[u] += sz[v]; }
    }
}
int getcentroid(int u, int pa, int tot){
    for(pi e: adj[u]){
        int v = e.first;
        if(v!=pa && sz[v]*2 > tot) return getcentroid(v, u, tot);
    }
    return u;
}
void dfs(int u, int pa, int d){
    ans += (ll)cnt[u]*d;
    for(pi e: adj[u]){
        int v = e.first, w = e.second;
        if(v != pa) dfs(v, u, d+w);
    }
}
int main(){
    scanf("%d %d", &K, &N);
    for(int i=1, x; i<=K; i++){
        scanf("%d", &x); cnt[x]++;
    }
    for(int i=1, u, v, w; i<N; i++){
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back({v, w}); adj[v].push_back({u, w});
    }
    getsz(1, 0);  int rt = getcentroid(1, 0, K); dfs(rt, 0, 0);
    printf("%lld\n", ans);
}