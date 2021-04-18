#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mm = 4e5 + 5;
int n, len[mm], dia; ll cnt[mm], num; vector<int> adj[mm];
void dfs(int u, int pa) {
    len[u] = 0; cnt[u] = 1;
    for (int v : adj[u]) {
        if (v == pa) continue;
        dfs(v, u);
        if (len[v] + len[u] + 1 > dia) {
            dia = len[v] + len[u] + 1; num = cnt[u] * cnt[v];
        } else if (len[v] + len[u] + 1 == dia) {
            num += cnt[u] * cnt[v];
        } 
        if (len[v] + 1 > len[u]) {
            len[u] = len[v] + 1; cnt[u] = cnt[v];
        } else if (len[v] + 1 == len[u]) {
            cnt[u] += cnt[v];
        }
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << dia + 1 << ' ' << num << '\n';
}