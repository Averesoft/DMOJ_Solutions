#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int mm = 5 * 1e5 + 5, mmm = 1e5 + 5;
int n, m, dis[mm], truedis[mm];
vector<pii> adj[mm];
void solve(int end, bool a) {
    memset(dis, 0, sizeof dis);
    memset(truedis, 0, sizeof dis);
    
}
int main() {
    cin >> n >> m;
    for (int i = 0, x, y, z; i < m; i++) {
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }
    int q; cin >> q;
    for (int i = 0, d; i < q; i++) {
        cin >> d;
        string s; cin >> s;
        bool type = (s == "White" ? true : false);
        solve(d, type);
    }
}