#include <bits/stdc++.h>
using namespace std;
const int mm = 1e5 + 5;
int n, ma = -1, a[mm], fre[mm], dp[mm];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; fre[a[i]]++;
        ma = max(ma, a[i]);
    }
    for (int i = 1; i <= ma; i++) {
        dp[i] = max(fre[i]*i + dp[i-2], dp[i-1]);
    }
    cout << dp[ma];
}