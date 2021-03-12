//knapsack moment
#include <bits/stdc++.h>
using namespace std;
const int mm = 100 + 5;
int N, T, dp[mm][mm]; 
int main() {
    cin >> N >> T;
    for (int i = 1, L; i <= N; i++) {
        cin >> L; 
        int pt = 0, px = 0;
        for (int j = 1, t, x; j <= L; j++) {
            cin >> t >> x; t += pt; x += px; pt = t; px = x;
            for (int k = 1; k <= T; k++) {
                dp[i][k] = max(dp[i][k], dp[i - 1][k]);
                if (k >= t) {
                    dp[i][k] = max(dp[i][k], dp[i - 1][k - t] + x);
                }
            }
        }
    }
    cout << dp[N][T];
}