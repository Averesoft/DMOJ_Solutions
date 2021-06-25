#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mm = 2 * 1e5 + 5;
int n, dis[mm];
vector<pii> adj[mm];
int main() {
    cin >> n;
    for (int i = 0, u, v, w; i < n; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
}