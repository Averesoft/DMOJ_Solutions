//last time I akd this early i had just started studying for ap exams :blobnotlike: 
#include <bits/stdc++.h>
using namespace std;
const int mm = 1e4 + 5;
int n, m;
string joey, animal;
int dp[mm][mm];
int main() {
    cin >> n >> m;
    cin >> joey >> animal;
    for (int i = 0; i <= n ; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = 0;
            } else if (i > 0 && j > 0 && joey[i-1] == animal[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = INT_MAX;
                if (i > 0 && j > 0) {
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                }
                if (i >= 1) {
                    dp[i][j] = min(dp[i][j], dp[i-1][j]);
                    if (i >= 2) {
                        dp[i][j] = min(dp[i][j], dp[i-2][j]);
                        if (i >= 3) {
                            dp[i][j] = min(dp[i][j], dp[i-3][j]);
                        }
                    }
                }
                if (j >= 1) {
                    dp[i][j] = min(dp[i][j], dp[i][j-1]);
                    if (j >= 2) {
                        dp[i][j] = min(dp[i][j], dp[i][j-2]);
                        if (j >= 3) {
                            dp[i][j] = min(dp[i][j], dp[i][j-3]);
                        }
                    }
                }
                dp[i][j]++;
            }
        }
    }
    cout << dp[n][m];
}
