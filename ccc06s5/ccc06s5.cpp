#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int mm = (1 << 20) + 5;
int m, n, a, b, c, dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool vis[mm];
vector<int> adj[mm];
queue<pii> q;
int main() {
    cin >> m >> n >> a >> b >> c;
    int tp = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            char ch; cin >> ch;
            if (ch == '*') {
                tp = tp | (1 << (i * n + j));
            }
        }
    }
    for (int i = 0, temp; i < (1 << (m * n)); i++) {
        temp = i;
        for (int j = 0; j < m; j++) {
            for (int k = 0, ans = 0; k < n; k++) {
                for (int l = 0; l < 8; l++) {
                    int x = j + dx[l], y = k + dy[l];
                    if (x < 0 || x >= m || y < 0 || y >= n) {
                        continue;
                    }
                    if (i & (1 << (x * n + y))) {
                        ans++;
                    }
                }
                if (i & (1 << (i * n + j))) {
                    if (ans < a || ans > b) {
                        temp = temp & ~(1 << (i * n + j));
                    }
                } else {
                    if (ans > c) {
                        temp = temp | (1 << (i * n + j));
                    }
                }
            }
        }
        if (temp != i) {
            adj[temp].push_back(i);
        }
    }
    int ans = -1;
    q.push({tp, 0});
    while(!q.empty()) {
        pii node = q.front(); q.pop();
        if (vis[node.first]) {
            continue;
        }
        vis[node.first] = 1;
        if (adj[node.first].size() == 0) {
            ans = node.second; break;
        }
        for (int v : adj[node.first]) {
            q.push({v, node.second + 1});
        }
    }
    cout << ans;
}