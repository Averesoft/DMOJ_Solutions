#include <bits/stdc++.h>
using namespace std;
const int mm = 1e6 + 5;
int n, q, a[mm], friends[mm];
bool vis[mm];
vector<int> adj[mm];
int solve(int x) {
    memset(vis, 0, sizeof vis);
    queue<int> q; q.push(x); vis[x] = 1;
    int total = 0;
    while(!q.empty()) {
        int node = q.front(); q.pop();
        total += a[node];
        for (int u : adj[node]) {
            if (!vis[u]) {
                vis[u] = 1;
                q.push(u);
            }
        }
    }
    return total;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        friends[i] = 1;
    }
    for (int i = 1; i <= q; i++) {
        int c; cin >> c;
        if (c == 1) {
            int A, B; cin >> A >> B;
            adj[A].push_back(B); 
            adj[B].push_back(A);
            int temp = friends[A];
            friends[A] += friends[B];
            friends[B] += temp;
        } else if (c == 2) {
            int A; cin >> A;
            cout << friends[A] << '\n';
        } else {
            int A; cin >> A;
            cout << solve(A) << '\n';
        }
    }
}