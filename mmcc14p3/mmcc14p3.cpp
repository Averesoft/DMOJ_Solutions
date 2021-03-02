#include <bits/stdc++.h>
using namespace std;
const int mm = 5 * 1e4 + 5;
int n, s;
vector<int> adj[mm];
int main() {
    cin >> n >> s;
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}