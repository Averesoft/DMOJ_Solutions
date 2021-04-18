#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mm = 3e4 + 4;
int B, N, D, w[mm], v[mm], dp[51];
set<pii, greater<pii>> card[51];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> B >> N >> D;
	for (int i = 1; i <= N; i++) {
		cin >> w[i] >> v[i];
		card[w[i]].insert({ v[i], i });
	}
	for (int i = 1, a, b, x, y; i <= D; i++) {
		cin >> a >> b >> x >> y;
		card[w[a]].erase({ v[a], a }); w[a] = b;
		card[w[a]].insert({ v[a], a });
		memset(dp, 0, sizeof dp);
		for (int j = 1; j <= B; j++) {
			int cnt = 0;
			for (auto it = card[j].begin(); it != card[j].end() && cnt < B / j; it++) {
				if (it->second >= x && it->second <= y) {
					cnt++;
					for (int k = B; k >= j; k--) {
						dp[k] = max(dp[k], dp[k - j] + it->first);
					}
				}
			}
		}
		cout << dp[B] << '\n';
	}

}