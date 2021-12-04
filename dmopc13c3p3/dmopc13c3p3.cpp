#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int mm = 1500 + 5;
int N, H;
int grid[mm][mm];
bool vis[mm][mm];
int main() {
    cin >> N >> H;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> grid[i][j];
        }
    }
    queue<pii> q; q.push({1, 1}); vis[1][1] = 1;
    bool flag = 0;
    while(!q.empty()) {
        pii node = q.front(); q.pop();
        int x = node.first, y = node.second;
        if (x == N && y == N) {
            flag = 1; break;
        }
        if (x - 1 >= 1 && !vis[x - 1][y] && abs(grid[x - 1][y] - grid[x][y]) <= H) {
            q.push({x - 1, y}); vis[x - 1][y] = 1;
        }
        if (y - 1 >= 1 && !vis[x][y - 1] && abs(grid[x][y - 1] - grid[x][y]) <= H) {
            q.push({x, y - 1}); vis[x][y - 1] = 1;
        }
        if (x + 1 <= N && !vis[x + 1][y] && abs(grid[x + 1][y] - grid[x][y]) <= H) {
            q.push({x + 1, y}); vis[x + 1][y] = 1;
        }
        if (y + 1 <= N && !vis[x][y + 1] && abs(grid[x][y + 1] - grid[x][y]) <= H) {
            q.push({x, y + 1}); vis[x][y + 1] = 1;
        }
    }
    cout << (flag ? "yes" : "no");
}