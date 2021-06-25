//HAHAHAHAAH TONY I USED TARJAN SCREW U
#include <bits/stdc++.h>
using namespace std;
const int mm = 1e4 + 5;
int n, k, idx = 0, ans = 0, dfn[mm], low[mm];
bool vis[mm], ins[mm];
vector<int> adj[mm];
vector<vector<int>> vvii;
stack<int> st;
void tarjan(int u){
    dfn[u] = low[u] = ++idx;
    st.push(u); ins[u] = vis[u] = 1;
    for (int v : adj[u]){
        if (!dfn[v]){
            tarjan(v); low[u] = min(low[u], low[v]);
        } else if (ins[v]){
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]){
        vector<int> vi;
        while (1){
            int c = st.top(); st.pop(); ins[c] = 0;
            vi.push_back(c);
            if (c == u) break;
        }
        vvii.push_back(vi);
    }
}
int main() {
    memset(dfn, 0, sizeof (dfn));
    cin >> n >> k;
    for (int i = 0, a, b, s_a, s_b; i < k; i++) {
        cin >> a >> b >> s_a >> s_b;
        (s_a > s_b ? adj[a].push_back(b) : adj[b].push_back(a));
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            tarjan(i);
        }
    }
    for (auto vi : vvii) {
        ans += (vi.size() > 1 ? vi.size() : 0);
    }
    cout << ans;
}
/*
#include <bits/stdc++.h>
using namespace std;
const int mm = 1e4 + 5;
int n, k, idx = 1, ans = 0, dfn[mm], low[mm];
bool vis[mm], ins[mm];
vector<int> adj[mm];
vector<vector<int>> vvii;
stack<int> st;
void tarjan(int u) {
    dfn[u] = low[u] = idx; idx++;
    st.push(u); ins[u] = vis[u] = 1;
    for (int v : adj[u]) {
        if (dfn[v] == 0) {
            tarjan(v); low[u] = min(low[u], low[v]);
        } else if (ins[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        vector<int> vi;
        while(st.size() > 0) {
            int u = st.top(); st.pop(); ins[u] = 0;
            vi.push_back(u);
            if (u == n) {
                break;
            }
        }
        if (vi.size() > 1) vvii.push_back(vi);
    }
}
int main() {
    memset(vis, 0, sizeof (vis));
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int a, b, s_a, s_b; cin >> a >> b >> s_a >> s_b;
        (s_a > s_b ? adj[a].push_back(b) : adj[b].push_back(a));
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            tarjan(i);
        }
    }
    for (auto vi : vvii) {
        ans += vi.size();
        for (int i : vi) {
            cout << i << ' ';
        }
    }
    cout << ans;
}
*/