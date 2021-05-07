#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mm = 1e6 + 5;
ll n, a[mm], dp[mm];
int main() {
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[0] = max((ll)0, a[0]);
    dp[1] = max(dp[0], a[1]);
    for (ll i = 2; i <= n; i++) {
        dp[i] = max(dp[i], dp[i - 2] + a[i]);
    }
    cout << dp[n];
}