#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mm = 200 + 5, mod = 1e5;
int n; ll dp[mm][mm]; string s;
bool cls(char c) { return c == ')' || c == ']' || c == '}'; }
bool opn(char c) { return c == '(' || c == '[' || c == '{'; }
int get(char a, char b) {
    if (a == '?' && b == '?') return 3;
    if (a == '?' || b == '?' || (a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}')) return 1;
    return 0; 
}
ll fun (int l, int r) {
    if (l >= r) return 1;
    if (dp[l][r] != -1) return dp[l][r];
    ll &ret = dp[l][r]; ret = 0;
    for (int m = l + 1; m <= r; m += 2) {
        if (cls(s[l]) || opn(s[m])) continue;
        int coef = get(s[l], s[m]);
        ret = ret + fun(l + 1, m - 1) * fun(m + 1, r) * coef;
        if (ret >= mod) {
            ret = ret % mod + mod;
        }
    }
    return ret;
}
int main() {
    cin >> n >> s;
    memset(dp, -1, sizeof dp);
    ll ans = fun(0, n - 1);
    if (ans >= mod) printf("%05lld\n", ans % mod);
    else printf("%lld\n", ans);
}