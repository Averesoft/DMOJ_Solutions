//:() :() :() :() :() :() :() :() bitmask
#include <bits/stdc++.h>
using namespace std;
const int mm = 20 + 5, mmm = (1 << 20) + 5;
int n;
double bond[mm][mm], dp[mmm];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> bond[j][i]; bond[j][i] /= 100.0;
        }
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < (1 << n); k++) {
                if (__builtin_popcount(k) != i || k & (1 << j)) {
                    continue;
                }
                dp[k | (1 << j)] = max(dp[k | (1 << j)], bond[j][i] * dp[k]);
            }
        }
    }
    printf("%.6f", dp[(1 << n) - 1] * 100);
}