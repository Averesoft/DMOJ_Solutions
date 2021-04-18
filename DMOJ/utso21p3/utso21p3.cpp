#include <bits/stdc++.h>
using namespace std;
const int mm = 1e5 + 5, mod = 1e9 + 7;
int n, h[mm], a[mm], dp[mm];
int main() {
    for (int i = 0; i < mm; i++) {
        dp[i] = 1;
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    int idx = 0;
    a[1] = 1; a[2] = 2;
    for (int i = 1; i < n; i++) {
        if (h[i] < h[idx]) {
            dp[i + 1] = dp[idx + 1];
        } else {
            dp[i + 1] = a[i + 1];
            idx = i;
        }
        a[i + 2] = a[i + 1] + dp[i + 1]; a[i + 2] %= mod;
    }
    cout << dp[n];
}