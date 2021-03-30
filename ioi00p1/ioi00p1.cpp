#include <bits/stdc++.h>
using namespace std;
const int mm = 5000 + 5;
int n; string s;
int dp[mm][mm];
int main() {
    memset(dp, 0, sizeof dp);
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            if (s[l] == s[r]) {
                dp[l][r] = dp[l + 1][r - 1];
            } else {
                dp[l][r] += 2;
            }
        }
    }
}