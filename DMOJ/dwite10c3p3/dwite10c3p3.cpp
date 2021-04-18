#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mm = 30 + 5, mod = 1000000;
int dp[mm];
int main() {
    int t = 5;
    while (t--) {
        int n; cin >> n;
        if (n % 2 != 0) {
            cout << 0 << '\n';
            continue;
        }
        dp[0] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = (3 * dp[i - 2]) % mod;
            for (int j = 4; i - j >= 0; j += 2) {
                dp[i] += (2 * dp[i - j] % mod) % mod;
            }
        }
        cout << dp[n] % mod << '\n';
    }
}
