#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int mm = 2 * 1e5 + 5;
int T, N, A, B, val, s;
int main() {
    for (cin >> T; T--;) {
        cin >> N >> A >> B; vector<int> p(A);
        for (int i = 0; i < A; i++) cin >> p[i];
        sort(p.begin(), p.end());
        priority_queue<pii> q; int ans = 0;
        if (p[0] > 1) q.push({p[0] - 1, 0});
        if (p.back() < N) q.push({N - p.back(), 0});
        for (int i = 1; i < A; i++) {
            int gap = p[i] - p[i - 1] - 1;
            if (gap <= 0) continue;
            if (gap & 1) q.push({(gap + 1) / 2, 3});
            else q.push({gap / 2, 2});
        }
        while(!q.empty() && B > 0) {
            tie(val, s) = q.top(); q.pop();
            ans += val; B--;
            if (s == 2) q.push({val, 0});
            if (s == 3 && val >= 2) q.push({val - 2, 1});
            if (s == 1) q.push({1, 0});
        }
        cout << ans << '\n';
    }
}