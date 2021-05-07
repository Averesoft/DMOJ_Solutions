#include <bits/stdc++.h>
using namespace std;
const int mm = 300 + 5, inf = 0x3f3f3f3f;
string s;
int n, dp[mm][mm];
bool match(char a, char b) {
    return (a == '(' && b == ')') || (a == '[' && b == ']');
}
int fun(int l, int r) {
    if (dp[l][r] != inf) return dp[l][r];
    if (l < r) {
        dp[l][r] = inf; 
        for (int m = l + 1; m <= r; m++) {
            if (match(s[l], s[m])) {
                dp[l][r] = min(dp[l][r], fun(l + 1, m - 1) + fun(m + 1, r));
            }
            else {
                dp[l][r] = min(dp[l][r], fun(l, m - 1) + fun(m + 1, r) + 1);
                dp[l][r] = min(dp[l][r], fun(l + 1, m) + fun(m + 1, r) + 1);
            }
        }
        return dp[l][r];
    } else if (l == r) {
        return 1;
    } else {
        return 0;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s; n = s.size();
    memset(dp, inf, sizeof(dp));
    cout << fun(0, n - 1) << '\n';
}
/*
#include <bits/stdc++.h>
using namespace std;
const int mm = 300 + 5, inf = 0x3f3f3f3f;
string s;
int n, dp[mm][mm];
bool match(char a, char b) {
    return (a == '(' && b == ')') || (a == '[' && b == ']');
}
int fun(int i, int j) {
    if (dp[i][j] != inf) return dp[i][j];
    if (i < j) {
        if (match(s[i], s[j])) {
            dp[i][j] = fun(i + 1, j - 1);
        } else {
            dp[i][j] = min(fun(i + 1, j), fun(i, j - 1)) + 1;
        }
        return dp[i][j];
    } else if (i == j) {
        return 1;
    } else {
        return 0;
    }
}
int main() {
    cin >> s; n = s.size();
    memset(dp, inf, sizeof (dp));
    cout << fun(0, n - 1);
}
*/