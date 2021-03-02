//kekw ez 15 pp
#include <bits/stdc++.h>
using namespace std;
const int mm = 10000 + 5, mmm = 2000 + 5;
int n, t;
int p[mmm][4], v[mmm][4];
int dp[mm];
int main() {
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> p[i][j] >> v[i][j];
        }
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = t; j >= 0; j--) {
            for (int l = 1; l <= 3; l++) {
                if (j >= p[i][l]) {
                    dp[j] = max(dp[j], dp[j-p[i][l]] + v[i][l]);
                }
            }
        }
    }
    cout << dp[t];
}