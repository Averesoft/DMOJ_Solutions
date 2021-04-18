#include <bits/stdc++.h>
using namespace std;
const int mm = 100000 + 5;
const int inf = 0x3f3f3f3f;
int dp[mm], n, k, h[mm];
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for (int i = 2; i <=n ; i++) {
        dp[i] = inf;
        for (int j = i - 1; j >= max(i - k, 1); j--) {
            dp[i] = min(dp[i], dp[j] + abs(h[i] - h[j]));
        }
    }
    cout << dp[n];
}