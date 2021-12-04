//why did it take me so long to do this
#include <bits/stdc++.h>
using namespace std;
const int mm = 15 + 1;
int N, p[mm], dp[(1 << mm) + 5];
int mem(int mask) {
    if (mask == 0) {
        return 0;
    }
    if (dp[mask] != -1) {
        return dp[mask];
    }
    int idx = -1, sum = 0;
    for (int i = 0; i < N; i++) {
        if (mask & (1 << i)) {
            sum++; idx = i;
        }
    }
    if (sum == 1) {
        return dp[mask] = p[idx];
    }
    int mi = 0x3f3f3f3f;
    for (int i = 0; i < N; i++) {
        if (!(mask & (1 << i))) {
            continue;
        }
        for (int j = i + 1; j < N; j++) {
            if (!(mask & (1 << j))) {
                continue;
            }
            if ((mask & ~(1 << i) & ~(1 << j)) == 0) {
                mi = min(mi, max(p[i], p[j]));
            } else {
                for (int k = 0; k < N; k++) {
                    if (mask & (1 << k) && k != i && k != j) {
                        continue;
                    }
                    mi = min(mi, mem((mask & ~(1 << i) & ~(1 << j)) | (1 << k)) + max(p[i], p[j]) + p[k]);
                }
            }
        }
    }
    return dp[mask] = mi;
}
int main() {
    cin >> N;
    for (int i = 0, p; i < N; i++) {
        cin >> p; 
    }
    for (int i = 0; i < (1 << mm); i++) {
        dp[i] = -1;
    }
    cout << mem((1 << N) - 1);
}