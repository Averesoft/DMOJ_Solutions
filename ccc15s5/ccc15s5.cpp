#include <bits/stdc++.h>
using namespace std;
int N, M, a[3002], b[102], dp[3002][102][102][2];
int fun(int i, int L, int R, int can) {
	if (dp[i][L][R][can] > 0) return dp[i][L][R][can];
	int best = 0;
	if (i <= N) {
		best = max(best, fun(i + 1, L, R, true));
		if (can) {
			best = max(best, a[i] + fun(i + 1, L, R, false));
		}
	}
	if (L <= R) {
		best = max(best, fun(i, L + 1, R, true));
		if (can) {
			best = max(best, b[R] + fun(i, L, R - 1, false));
		}
	}
	return dp[i][L][R][can] = best;
}
int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> a[i];
	cin >> M;
	for (int i = 1; i <= M; i++) cin >> b[i];
	sort(b + 1, b + M + 1);
	cout << fun(1, 1, M, 1) << '\n';
}