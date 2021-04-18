#include <bits/stdc++.h>
using namespace std;
const int mm = 1000+5;
int D, I, R;
int dp[mm][mm];
string a, b;
int main() {
    cin >> D >> I >> R;
    cin >> a >> b;
    for (int i = 0; i <= a.size(); i++) {
        for (int j = 0; j <= b.size(); j++) {
            if (i == 0) {
                dp[i][j] = j*I;
            } else if (j == 0) {
                dp[i][j] = i*D;
            } else if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = dp[i-1][j]+D;
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]+R);
				dp[i][j] = min(dp[i][j], dp[i][j-1]+I);
            }
        }
    }
    cout << dp[a.size()][b.size()];
}