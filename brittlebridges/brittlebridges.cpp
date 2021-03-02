#include <bits/stdc++.h>
using namespace std;
const int mm = 200000 + 5;
int n, v[mm];
int adj[mm][mm];
vector<int> edg[mm];
void dijk() {
    
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        edg[a].push_back(b); edg[b].push_back(a);
        cin >> adj[a][b]; adj[b][a] = adj[a][b];
    }
    dijk();
}