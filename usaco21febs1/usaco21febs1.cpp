#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int mm = 1e4 + 5;
int n;
bool grid[mm][mm];
vector<pii> cows;
queue<pii> q;
void change(int x, int y) {
    if (!grid[x][y]) {
        return;
    }
    int adj = 0;
    adj += grid[x + 1][y];
    adj += grid[x - 1][y];
    adj += grid[x][y + 1];
    adj += grid[x][y - 1];
    if (adj == 3) {
        if (!grid[x + 1][y]) {
            q.push({x + 1, y});
        }
        if (!grid[x - 1][y]) {
            q.push({x - 1, y});
        }
        if (!grid[x][y + 1]) {
            q.push({x, y + 1});
        }
        if (!grid[x][y - 1]) {
            q.push({x, y - 1});
        }
    }
}
int main() {
    cin >> n;
    int cows = 0;
    for (int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y; x += 1000; y += 100;
        q.push({x, y});
        while (!q.empty()) {
            pii front = q.front(); q.pop();
            if (grid[front.first][front.second]) {
                continue;
            }
            cows++; 
            grid[front.first][front.second] = true;
            change(front.first, front.second);
            change(front.first + 1, front.second);
            change(front.first - 1, front.second);
            change(front.first, front.second + 1);
            change(front.first, front.second - 1);
        }
        cout << cows - i << '\n';
    }
}