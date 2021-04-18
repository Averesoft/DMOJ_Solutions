#include <bits/stdc++.h>
using namespace std;
const int mm = 5000 + 5;
int n; string s, t;
int dp[2][mm];
int main() {
    cin >> n;
    cin >> s;
    t = s; reverse(t.begin(), t.end());
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[(i + 1) % 2][j] = dp[i % 2][j - 1] + 1;
            } else {
                dp[(i + 1) % 2][j] = max(dp[i % 2][j], dp[(i + 1) % 2][j - 1]);
            }
        }
    }
    cout << n - dp[(n + 1) % 2][n];
}