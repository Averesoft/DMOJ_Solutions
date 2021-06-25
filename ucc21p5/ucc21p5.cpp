//memoizing is the bestoizing
#include <bits/stdc++.h>
using namespace std;
const int mm = 2 + 5, mmm = 300 + 5;
int h1, w1, h2, w2, dp[mm][mmm][mm][mmm];
int mem(int a, int b, int c, int d) {
    if (dp[a][b][c][d] != 0) {
        return dp[a][b][c][d];
    } 
    if (a == 1 && b == 1 && c == 1 && d == 1) {
        return dp[a][b][c][d] = -1;
    }
    for (int i = 1; i < a; i++) {
        if (mem(i, b, a - 1, b) == -1) {
            return dp[a][b][c][d] = 1;
        }
    }
    for (int i = 1; i < b; i++) {
        if (mem(a, i, a, b - i) == -1) {
            return dp[a][b][c][d] = 1;
        }
    }
    for (int i = 1; i < c; i++) {
        if (mem(i, d, c - i, d) == -1) {
            return dp[a][b][c][d] = 1;
        }
    }
    for (int i = 1; i < d; i++) {
        if (mem(c, i, c, d - i) == -1) {
            return dp[a][b][c][d] = 1;
        }
    }
    if (a == 2) {
        if (mem(1, b, c, d) == -1) {
            return dp[a][b][c][d] = 1;
        }
    }
    if (c == 2) {
        if (mem(a, b, 1, d) == -1) {
            return dp[a][b][c][d] = 1;
        }
    }
    for (int i = 1; i <= 10 && b - i >= 1; i++) {
        if (mem(a, b - i, c, d) == -1) {
            return dp[a][b][c][d] = 1;
        }
    }
    for (int i = 1; i <= 10 && d - i >= 1; i++) {
        if (mem(a, b, c, d - i) == -1) {
            return dp[a][b][c][d] = 1;
        }
    }
    return dp[a][b][c][d] = -1;
}
int main() {
    memset(dp, 0, sizeof (dp));
    cin >> h1 >> w1 >> h2 >> w2;
    if (mem(h1, w1, h2, w2) == 1) {
        cout << 'W';
    } else {
        cout << 'L';
    }
}