#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mm = 1000000 + 5, inf = 0x3f3f3f3f;
ll n, a[mm], dp[mm];
int main() {
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[1] = a[1];
    dp[2] = a[1] + a[2] - min(a[1], a[2]) / 4;
    for (ll i = 3; i <= n; i++) {
        dp[i] = min(dp[i - 1] + a[i], min(dp[i - 2] + a[i - 1] + a[i] - min(a[i - 1], a[i]) / 4, dp[i - 3] + a[i - 2] + a[i - 1] + a[i] - min(min(a[i], a[i - 1]), a[i - 2]) / 2));
    }
    cout << dp[n];
}