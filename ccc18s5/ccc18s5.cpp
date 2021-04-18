#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mm = 1e5 + 5;
struct E { int u, v, w; bool f; };
int N, M, P, Q, r[mm], c[mm], row, col; vector<E> e; ll tot, mst;
bool cmp(E x, E y) { return x.w < y.w; }
int fd(int d, int p[]) {
	if (d != p[d]) p[d] = fd(p[d], p);
	return p[d];
}
int main()
{
	cin >> N >> M >> P >> Q; row = N; col = M;
	for (int i = 1, u, v, w; i <= P; i++) {
		cin >> u >> v >> w;
		e.push_back(E{ u, v, w, false }); tot += (ll)N * w;
	}
	for (int i = 1, u, v, w; i <= Q; i++) {
		cin >> u >> v >> w;
		e.push_back(E{ u, v, w, true }); tot += (ll)M * w;
	}
	sort(e.begin(), e.end(), cmp);
	for (int i = 1; i <= N; i++) r[i] = i;
	for (int i = 1; i <= M; i++) c[i] = i;
	for (E x : e) {
		if (x.f) {
			if (row == 1) continue;
			int fu = fd(x.u, r), fv = fd(x.v, r);
			if (fu != fv) {
				r[fu] = fv; row--; mst += (ll)x.w * col;
			}
		}
		else {
			if (col == 1) continue;
			int fu = fd(x.u, c), fv = fd(x.v, c);
			if (fu != fv) {
				c[fu] = fv; col--; mst += (ll)x.w * row;
			}
		}
		if (row == 1 && col == 1) break;
	}
	cout << tot - mst << '\n';
}