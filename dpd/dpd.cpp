#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mm = 100 + 5, mmm = 1e9 + 5;
ll dp[2][mmm];
int v[mm], w[mm];
int N, W;
int main()
{
	cin >> N >> W;
	for (int i = 1; i <= N; i++) {
		cin >> w[i] >> v[i];
	}
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= W; j++) {
			if (i == 0 || j == 0) {
				dp[1][j] = 0;
			}
			else if (w[i] > j) {
				dp[1][j] = dp[0][j];
			}
			else if (i > 0 && j >= w[i]) {
				dp[1][j] = max(v[i] + dp[0][j - w[i]], dp[0][j]);
			}
		}
        for (int j = 0; j <= W; j++) {
            dp[0][j] = dp[1][j];
        }
	}
	cout << dp[1][W];
}