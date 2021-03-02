//OH YOU CAN KEEP TRACK OF INDICES
#include <bits/stdc++.h>
using namespace std;
const int mm = 1000000+5;
int jef[mm], leo[mm], idx1[mm], idx2[mm];
int dp[mm];
int main() {
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> jef[i];
        idx1[jef[i]] = i;
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> leo[i];
        idx2[i] = idx1[leo[i]];
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        if (idx2[i] == 0) {
            continue;
        } 
        if (ans == 0 || idx2[i] > dp[ans-1]) {
            dp[ans++] = idx2[i];
        } else {
            int temp = lower_bound(dp, dp+ans, idx2[i]) - dp;
            dp[temp] = idx2[i];
        }
    }
    cout << ans;   
}