#include <bits/stdc++.h>
using namespace std;
const int mm = 500 + 5, mod = 1e9 + 7;
int N, K, dp[2][mm][mm];
int main() {
    cin >> N >> K;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            for (int k = 0; k <= K; k++) {
                int temp = dp[i % 2][j][k];
                if (i == 0) {
                    (j == 0 && k == 0 ? temp = 1 : temp = 0);
                } else if (i < j) {
                    temp = 0;
                } else {
                }
            }
        }
    }
}