#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef long long ll;
typedef pair<int, int> pi;
const int MM = 2e5+5, MV = 1e6+2;
int N, K, freq[MV], sz[MM], tmp[4*MM], p; bool done[MM]; vector<pi> adj[MM]; ll dis[MM], cnt[MM], ans[MM], tot;
void getsz(int u, int pa){
    sz[u] = 1;
    for(pi e: adj[u])
        if(!done[e.f] && e.f!=pa) { getsz(e.f, u); sz[u]+=sz[e.f]; }
}
int getcent(int u, int pa, int tot){
    for(pi e: adj[u])
        if(!done[e.f] && e.f!=pa && sz[e.f]*2 > tot) return getcent(e.f, u, tot);
    return u;
}
void upd(int u, int pa, int d, int val){
    freq[d]+=val; tmp[p++]=d;
    for(pi e: adj[u])
        if(!done[e.f] && e.f!=pa && d+e.s <= K) upd(e.f, u, d+e.s, val);
}
void dfs(int u, int pa, int d, int cent){
    cnt[u] = freq[K-d]; tot += freq[K-d];
    if(d==K){ tot++; cnt[cent]++; }
    for(pi e: adj[u])
        if(!done[e.f] && e.f!=pa && d+e.s <= K) { dfs(e.f, u, d+e.s, cent); cnt[u] += cnt[e.f]; }
    ans[u] += cnt[u];
}
void solve(int rt){
    getsz(rt, -1); rt = getcent(rt, -1, sz[rt]);
    done[rt]=1; freq[0] = 1; cnt[rt]=0; p = 0; tmp[p++]=0;
    for(pi e: adj[rt])
        if(!done[e.f] && e.s <= K) upd(e.f, rt, e.s, 1);
    for(pi e: adj[rt]){
        if(done[e.f] || e.s > K) continue;
        upd(e.f, rt, e.s, -1);
        dfs(e.f, rt, e.s, rt); cnt[rt]+=cnt[e.f];
        upd(e.f, rt, e.s, 1);
    }
    ans[rt]+=cnt[rt]/2;
    for(int i=0; i<p; i++) freq[tmp[i]] = 0;
    for(pi e: adj[rt])
        if(!done[e.f]) solve(e.f);
}
int main(){
    //freopen("test.txt", "r", stdin);
    scanf("%d %d", &N, &K);
    for(int i=1, u, v, w; i<N; i++){
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back({v, w}); adj[v].push_back({u, w});
    }
    solve(1); tot /= 2;
    for(int i=1; i<=N; i++){
        ll g = __gcd(ans[i], tot);
        if(ans[i] == 0) printf("0 / 1\n");
        else printf("%lld / %lld\n", ans[i]/g, tot/g);
    }
}