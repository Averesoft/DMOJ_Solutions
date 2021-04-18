#include <bits/stdc++.h>
using namespace std;
const int mm = 100 + 5;
int n, a[mm], dp[mm * 2][mm * 2];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i]; 
        dp[i][i] = a[i] % 2; dp[i + n][i + n] = a[i] % 2;
    }
    for (int le = 1; le < n; le++) {
        for (int l = 0; l + le < n * 2; l++) {
            int r = l + le;
            dp[l][r] = max(dp[l][l] - dp[l + 1][r], dp[r][r] - dp[l][r - 1]);
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i][i] - dp[i + 1][i - 1 + n] > 0) {
            cnt++;
        }
    }
    cout << cnt;
}