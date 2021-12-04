#include <bits/stdc++.h>
using namespace std;
const int mm = 1000 + 5, mmm = mm * 15;
int n, a[mm], cnt = 0;
bool dp[mm][mmm];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++) {
        dp[i][a[i - 1]] = 1;
        for (int j = 1; j <= sum; j++) {
            if (dp[i - 1][j]) {
                dp[i][j] = 1;
                dp[i][j + a[i - 1]] = 1;
            }
        }
    }
    for (int i = 0; i <= sum; i++) {
        if (dp[n][i]) {
            cnt++;
        }
    }
    cout << cnt;
}