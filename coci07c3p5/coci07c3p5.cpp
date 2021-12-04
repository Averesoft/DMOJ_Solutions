#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[16], b[16], s, n; string A, B; ll dp[16][136][2][2], mi = 1e18;
ll fun(int pos, int sum, int lo, int hi, ll num) {
    if (pos == n) {
        if (sum == s) {
            mi = min(mi, num); return 1;
        }
    }
    if (sum > s) {
        return 0;
    }
    if (dp[pos][sum][lo][hi] != -1) {
        return dp[pos][sum][lo][hi];
    }
    int x = lo ? a[pos] : 0, y = hi ? b[pos]: 9; ll ret = 0;
    for (int i = x; i <= y; i++) {
        ret += fun(pos + 1, sum + i, lo && i == a[pos], hi && i == b[pos], num * 10 + i); 
    }
    return dp[pos][sum][lo][hi] = ret;
}
int main() {
    cin >> A >> B >> s; n = B.size();
    for (int i = 0; i < n; i++) {
        b[i] = B[i];
    }
    for (int i = n - 1, j = A.size() - 1; j >= 0; i--, j--) {
        a[i] = A[j] - '0';
    }
    memset(dp, -1, sizeof (dp));
    cout << fun(0, 0, 1, 1,0) << '\n' << mi;
}