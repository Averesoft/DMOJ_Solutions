#include <bits/stdc++.h>
using namespace std;
const int mm = 3000 + 5;
string s, t;
int dp[mm][mm];
int main() {
    cin >> s >> t;
    for (int i = 0; i <= s.size(); i++) {
        for (int j = 0; j <= t.size(); j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int i = s.size(), j = t.size();
    int idx = dp[s.size()][t.size()];
    char ans[mm];
    while (i > 0 && j > 0) {
        if (s[i - 1] == t[j - 1]) {
            ans[idx - 1] = s[i - 1];
            i--; j--; idx--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    for (int i = 0; i < dp[s.size()][t.size()]; i++) {
        cout << ans[i];
    }

}