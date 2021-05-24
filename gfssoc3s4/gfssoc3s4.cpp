#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mm = 100 + 5, mod = 1000000007;
int r, c;
ll dp[mm][3000], ans = 0;
vector<ll> vc;
int main() {
    cin >> r >> c;
    for (int mask = 0; mask < 1 << c - 2; mask++) {
        if ((mask & mask << 1) == 0 && (mask & mask << 2) == 0) {
            vc.push_back(mask); dp[0][vc.size() - 1] = 1; ans++;
        }
    }
    ans -= dp[0][0];
    for (int i = 1; i < r - 1; i++) {
        for (int j = 0; j < vc.size(); j++) {
            int mask = vc[j];
            for (int k = 0; k < vc.size(); k++) {
                ll mask2 = vc[k], nmask = mask2 | mask2 << 1  | mask2 >> 1;
                if ((nmask & mask) == 0) {
                    dp[i][j] += dp[i - 1][k];
                }
            }
            dp[i][j] %= mod; ans = (ans + dp[i][j]) % mod;
        }
        ans = (ans - dp[i][0] + mod) % mod;
    }
    cout << ans;
}