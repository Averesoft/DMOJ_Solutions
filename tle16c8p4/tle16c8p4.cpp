#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, mm = 1e5 + 3;
int X, D, N, P, f[mm], dp[mm], dif[mm];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> X;
    if (X == 1) {
        cin >> D >> N >> P;
        for (int i = 1, pos, fuel; i <= P; i++) {
            cin >> pos >> fuel;
            f[pos] = fuel;
        }
        dp[0] = 1; dif[1]++; dif[N + 1] = -1;
        for (int i = 1; i <= D; i++) {
            dp[i] = dif[i] = (dif[i] + dif[i - 1]) % mod;
            if (f[i]) {
                dif[i + 1] = (dif[i + 1] + dp[i]) % mod;
                int t = min(i + f[i] + 1, D + 1);
                dif[t] = (dif[t] - dp[i] + mod) % mod;
            }
        }
        cout << dp[D] << '\n';
    } else {
        cout << "todo";
    }
}