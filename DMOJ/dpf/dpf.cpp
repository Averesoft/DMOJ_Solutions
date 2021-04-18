#include <bits/stdc++.h>
using namespace std;
const int mm = 3000 + 5;
string s, t;
int dp[mm][mm];
int main() {
    cin >> s >> t;
    for (int i = 1; i <= s.size(); i++) {
        for (int j = 1; j <= t.size(); j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else if (s[i - 1w] != t[j - 1]) {
                dp[i][j] = max(dp[i-1][j], dp[i][j - 1]);
            }
        }
    }
}