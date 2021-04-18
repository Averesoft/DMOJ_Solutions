#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000000 + 7, mm = 1e6 + 5;
ll dp[mm];
int main() {
    ll n; cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; i*=2) {
        for (int j = i; j <= n; j++) {
            dp[j] = (dp[j] + dp[j - i]) % mod;
        }
    }
    cout << dp[n];
}