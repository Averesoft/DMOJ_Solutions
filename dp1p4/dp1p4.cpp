#include <bits/stdc++.h>
using namespace std;
const int mm = 100000 + 5, mod = 10007;
string s;
int dp[mm], alpha[26];
int main() {
    cin >> s;
    for (int i = 1; i <= s.size(); i++) {
        dp[i] = dp[i - 1] * 2;
        if (alpha[s[i - 1] - 97] == 0) {
            dp[i]++; alpha[s[i - 1] - 97] = i;
        } else {
            dp[i] -= dp[alpha[s[i - 1] - 97] - 1]; alpha[s[i - 1] - 97] = i;
        }
        dp[i] %= mod;
    }
    cout << dp[s.size()];
}