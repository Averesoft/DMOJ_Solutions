#include <bits/stdc++.h>
using namespace std;
const int mm = 10000 + 5;
int N, M, cnt = 0;
short grid[mm][mm];
int main() {
    cin >> N >> M;
    for (int i = 0, x, y, w, h; i < M; i++) {
        cin >> x >> y >> w >> h; x++; y++;
        grid[x][y]++;
        grid[x + w][y + h]++;
        grid[x + w][y]--;
        grid[x][y + h]--;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
            if (grid[i][j] % 2 != 0) {
                cnt++;
            }
        }
    }
    cout << cnt;
}