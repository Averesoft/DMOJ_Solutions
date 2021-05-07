#include <bits/stdc++.h>
using namespace std;
const int mm = 100 + 5, mmm = 1e9 + 5;
int N, W, w[mm], v[mm];
int main() {
    cin >> N >> W;
    int ma = -1;
    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
        ma = max(ma, w[i]);
    }
    vector<int> dp(ma + 5);
    for (int i = 0; i < N; i++) {
        for (int j = W; j >= w[i]; j--) {
            dp[j] = max(dp[j], v[i] + dp[j - w[i]]);
        }
    }
    cout << dp[W];
}