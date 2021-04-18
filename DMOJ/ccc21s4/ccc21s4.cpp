#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> plli;
const int mm = 2 * 1e5 + 5;
const int maximum = 0x3f3f3f3f;
vector<int> adj[mm], rev[mm];
set<plli> st;
int n, w, d, s[mm], dis[mm], idx[mm];
bool vis[mm];
void revbfs() {
    queue<int> q;
    q.push(n); vis[n] = true; dis[n] = 0;
    while(!q.empty()) {
        int node = q.front(); q.pop();
        for (int u : rev[node]) {
            if (!vis[u]) {
                vis[u] = true;
                q.push(u);
                dis[u] = dis[node] + 1;
            }
        }
    }
}
int main() {
    memset(dis, maximum, sizeof dis);
    memset(vis, false, sizeof vis);
    cin >> n >> w >> d;
    for (int i = 1, a, b; i <= w; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        rev[b].push_back(a);
    }
    revbfs();
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        idx[s[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        st.insert({idx[i] + dis[i], i});
    }
    for (int i = 1, x, y; i <= d; i++) {
        cin >> x >> y;
        st.erase({idx[s[x]] + dis[s[x]], s[x]}); st.erase({idx[s[y]] + dis[s[y]], s[y]});
        int temp = s[x];
        s[x] = s[y];
        s[y] = temp;
        idx[s[y]] = y;
        idx[s[x]] = x;
        st.insert({idx[s[x]] + dis[s[x]], s[x]}); st.insert({idx[s[y]] + dis[s[y]], s[y]});
        cout << st.begin()->first-1 << '\n';
    }
}