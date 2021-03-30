#include <bits/stdc++.h>
using namespace std;
const int mm = 5000 + 5;
int n, m;
vector<int> adj[mm];
int main() {
    cin >> n >> m;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        bool flag = 1;
        for (int j = 1; j <= n; j++) {
            if ((1 << (j - 1)) & i) {
                for (int u : adj[j]) {
                    if ((1 << (u - 1)) & i) {
                        flag = 0;
                        break;
                    }
                }
            }
            if (!flag) break;
        }
        if (flag) ans++;
    }
    cout << ans;
}