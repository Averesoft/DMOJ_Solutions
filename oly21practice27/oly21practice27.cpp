#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int mm = 1e6 + 5;
int n, m, a[mm], v[mm], s[mm], t[mm], dif[mm];
bool chk(int x) {
    memset(dif, 0, sizeof dif);
    for (int i = 1; i <= x; i++) {
        dif[s[i]] += v[i]; dif[t[i] + 1] -= v[i];
    }
    for (int i = 1; i <= n; i++) {
        dif[i] += dif[i - 1];
        if (dif[i] > a[i]) return false;
    }
    return true;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> v[i] >> s[i] >> t[i];
    }
    int lo = 1, hi = m, ans = m + 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (chk(mid)) lo = mid + 1;
        else ans = mid, hi = mid - 1;
    }
    if (ans > m) cout << "0\n";
    else cout << "-1\n" << ans << '\n';
}