#include <bits/stdc++.h>
using namespace std;
int dp[50 + 5][26 + 5];
int main() {
    string s; cin >> s;
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i <= s.size(); i++) {
        for (int j = 0; j <= alpha.size(); j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (s[i - 1] == alpha[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << 26 - dp[s.size()][alpha.size()] << '\n';
}