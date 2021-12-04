#include <bits/stdc++.h>
using namespace std;
const int mm = 10000 + 5;
int N, M, X, Y;
bool vis[mm];
vector<int> adj[mm];
void dfs(int u) {
    for (int v : adj[u]) {
        if (!vis[v]) {
            vis[v] = 1; dfs(v);
        }
    }
}
int main() {
    cin >> N >> M;
    for (int i = 0, A, B; i < M; i++) {
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    cin >> X >> Y;
    vis[X] = 1; dfs(X);
    cout << vis[Y];
}