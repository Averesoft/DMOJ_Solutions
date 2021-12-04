#include <bits/stdc++.h>
using namespace std;
int R, C, n, e[2], p[14] = {1}, mask;
string g; double dp[2][1594323];
int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
void decode (int grid[], int mask) {
    for (int i = R * C - 1; i >= 0; i--) {
    }
}
double fun(int p, int mask) {
    if (dp[p][mask] >= 0) return dp[p][mask];
    double & ret = dp[p][mask]; int grid[14]; decode(grid, mask);
    vector<double> tmp;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int idx = i * C + j;
            if (grid[idx] == p + 1) {
                for (int k = 0; k < 4; k++) {
                    int nr = i + d[k][0], nc = j + d[k][1], nxt = nr * C + nc;
                    if (nr < 0 || nr >= R || nc < 0 || nc >= C || !grid[nxt]) {
                        continue;
                    }
                    int nmask = mask - grid[idx] * p[n - idx -1] - grid[nxt] * p[n - nxt - 1] + grid[idx] * p[n - nxt - 1];
                    tmp.push_back(1.0 - fun(!p, nmask));
                }
            }
        }
    }
    sort(tmp.begin(), tmp.end(), greater<double>());
    double sum = 0.0; int sz = min(e[p], (int) tmp.size());
    if (sz == 0) return ret = 0.0;
    for (int i = 0; i < sz; i++) {
        sum += tmp[i];
    }
    return ret = sum / sz;
}
int main() {
    cin >> R >> C; n = R * C;
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] * 3;
    }
    for (int i = 0; i < R; i++) {
        cin >> g;
        for (int j = 0; j < C; j++) {
            int val = (g[j] == 'K' ? 1 : (g[j] == 'D' ? 2 : 0));
            mask = mask * 3 + val;
        }
    }
    cin >> e[0] >> e[1];
    fill_n(&dp[0][0], 2 * 1594323, -1.0);
    printf("%.3f\n", fun(0, mask));
}