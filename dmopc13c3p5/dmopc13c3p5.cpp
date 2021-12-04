#include <bits/stdc++.h>
using namespace std;
const int mmm = 300 + 5, mmu = 100 + 5;
int M, U, R, dp[mmm][mmu];
int main() {
    cin >> M >> U >> R;
    for (int i = 1, V, T, F; i <= R; i++) {
        cin >> V >> T >> F;
        for (int j = U; j >= F; j--){
            for (int k = M; k >= T; k--) {
                dp[i][j] = max(dp[i][j], dp[i - T][j - F] + V);
            }
        }
    }
    cout << dp[M][U];
}