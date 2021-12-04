#include <bits/stdc++.h>
using namespace std;
const int mm = 2000 + 5;
int N, M, A, B;
bool vis[mm];
vector<int> adj[mm];
void dfs(int u) {
    for (int v : adj[u]) {
        if (!vis[v]) {
            vis[v] = 1; 
            dfs(v);
        }
    }
}
int main() {
    cin >> N >> M >> A >> B;
    for (int i = 0, X, Y; i < M; i++) {
        cin >> X >> Y; adj[X].push_back(Y); adj[Y].push_back(X);
    }
    vis[A] = 1; dfs(A);
    cout << (vis[B] ? "GO SHAHIR!" : "NO SHAHIR!");
}