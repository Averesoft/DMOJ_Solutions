#include <bits/stdc++.h>
using namespace std;
const int mm = 100000 + 5;
int n, a[mm], dp[mm];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    dp[0] = a[0]; 
    dp[1] = max(a[0], a[1]);
    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 2] + a[i], dp[i - 1]);
    }
    cout << dp[n - 1];
}