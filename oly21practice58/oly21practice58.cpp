#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mm = 2 * 1e5 + 5;
ll n, k, idx = 0, x[mm], dfn[mm], low[mm];
bool vis[mm], ins[mm];
vector<ll> adj[mm];
stack<ll> st;
void tarjan(ll u) {
    k--;
   // cout << u << ' ';
    if (k == -1 || x[u] == u) {
       // cout << '\n';
        cout << u;
        return;
    } 
    dfn[u] = low[u] = ++idx;
    st.push(u); ins[u] = vis[u] = 1;
    for (ll v : adj[u]) {
        if (!dfn[v]) {
            tarjan(v); low[u] = min(low[u], low[v]);
        } else if (ins[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        vector<ll> vi;
        while(1) {
            ll c = st.top();
            vi.push_back(c); st.pop(); ins[c] = 0;
            if (c == u) {
                break;
            }
        }
        if (vi.size() > 1) {
            reverse(vi.begin(), vi.end());
            cout << vi[(k + vi.size()) % vi.size()]; 
            return;
        }
    }
}
int main() {
    cin >> n >> k;
    for (ll i = 1; i <= n; i++) {
        cin >> x[i]; adj[i].push_back(x[i]);
    }
    tarjan(1);
}