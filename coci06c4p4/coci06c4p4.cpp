#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
int N, C, dp[1000 + 5][10000 + 5];
int main() {
    cin >> N >> C;
    for (int i = 1; i <= N; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= C; j++) {
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
            if (j >= i) {
                dp[i][j] = ((dp[i][j] - dp[i - 1][j - i]) % mod + mod) % mod;
            }
        }
    }
    cout << (dp[N][C] - dp[N][C - 1] + mod) % mod;
}