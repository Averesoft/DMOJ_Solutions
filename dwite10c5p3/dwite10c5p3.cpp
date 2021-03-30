#include <bits/stdc++.h>
using namespace std;
const int mm = 1e6 + 5;
bool dp[mm];
void solve() {
    memset(dp, 0, sizeof dp);
    int n, sum = 0; cin >> n;
    for (int i = 0, w; i < n; i++) {
        cin >> w; sum += w;
        for (int j = mm - w - 1; j >= 0; j--) {
            if (dp[j] ){
                dp[j + w] = 1;
            }
        }
        dp[w] = 1;
    }
    for (int i = sum / 2; i >= 0; i--) {
        if (dp[i]) {
            cout << sum - 2 * i << '\n';
            return;
        }
    }
    cout << sum << '\n';
}
int main() {
    int t = 5;
    while(t--) {
        solve();
    }
}