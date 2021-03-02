#include <bits/stdc++.h>
using namespace std;
typedef pair<char, int> pci;
int m, n, k;
map<pci, bool> mp, done;
map<pci, int> ok;
vector<pci> vc;
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> m;
	cin >> n;
	cin >> k;
	for (int i = 1; i <= m; i++) {
		mp[{'R', i}] = false;
		done[{'R', i}] = false;
	}
	for (int j = 1; j <= n; j++) {
		mp[{'C', j}] = false;
		done[{'C', j}] = false;
	}
	int rcount = 0, ccount = 0, ans = 0;
	for (int i = 1; i <= k; i++) {
		char c; int num; cin >> c >> num;
		ok[{c, num}]++;
		vc.push_back({ c, num });
	}
	
	for (int i = 0; i < vc.size(); i++) {
		if (!done[vc[i]]) {
			done[vc[i]] = true;
			if (ok[vc[i]] % 2 == 1) {
				if (vc[i].first == 'R') {
					rcount++;
					ans += (n - 2 * ccount);
				}
				else {
					ccount++;
					ans += (m - 2 * rcount);
				}
			}
		}
	}
	cout << ans;
}