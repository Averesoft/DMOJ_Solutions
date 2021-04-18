#include <bits/stdc++.h>
using namespace std;
const int mm = 200 + 5;
int n, k[mm], dp[mm][mm];
int main() {
    while(true) {
        cin >> n;
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            cin >> k[i];
        }
        for (int i = 0; i < n; i++) {
            if (i != n) {
                dp[i][i + 1] = 0;
            }
            dp[i][i] = 0;
        }
        for (int i = 2; i < n; i++) {
            for (int j = 0; i + j < n; j++) {
                dp[j][i + j] = 0;
                for (int l = j + 1; l < i + j; l++) {
                    dp[j][i + j] = max(dp[j][i + j], dp[j][l] + dp[l][i + j] + k[j] + k[l] + k[i + j]);
                }
            }
        }
        cout << dp[0][n - 1] << '\n';
    }
}
//Why did this take so long its just interval dp LOL