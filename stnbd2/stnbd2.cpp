#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mm = 1e5 + 3, mod = 1e9 + 7;
int N, M, in[mm];
vector<int> adj[mm]; 
ll dp[mm], cnt[mm], ans;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i = 1, u, v; i <= M; i++) {
        cin >> u >> v; adj[u].push_back(v); in[v]++;
    }
    queue<int> q;
    for(int i=1; i<=N; i++){
        if(in[i] == 0) { 
            q.push(i); dp[i] = 0; cnt[i] = 1;
        }
    }
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : adj[u]){
            dp[v] = (dp[v] + dp[u] + cnt[u]) % mod;
            cnt[v] = (cnt[v] + cnt[u]) % mod;
            in[v]--;
            if(in[v] == 0) {
                q.push(v);
            }
        }
    }
    for(int i = 1; i <= N; i++) {
        if(adj[i].empty()) {
            ans = (ans + dp[i])%mod;
        }
    }
    cout << ans << endl;
}