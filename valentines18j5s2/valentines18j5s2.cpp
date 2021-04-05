#include <bits/stdc++.h>
using namespace std;
const int mm = 10 + 5, inf = 0x3f3f3f3f;
int n, m, c[mm], d[mm][mm], q[mm], mask[mm];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> d[i][0];
        for (int j = 1; j <= n; j++) {
            cin >> d[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> q[i];
    }
    int mi = inf;
    for (int i = 0; i < 1 << m; i++) {
        memset(mask, 0, sizeof mask);
        int ans = 0;
        for (int j = 1; j <= m; j++) {
            if (i & (1 << (j - 1))) {
                ans += d[j][0];
                for (int k = 1; k <= n; k++) {
                    mask[k] += d[j][k];
                }
            }
        }
        for (int j = 1; j <= n; j++) {
            if (mask[j] > q[j]) {
                ans = inf;
                break;
            } else if (mask[j] < q[j]) {
                ans += (q[j] - mask[j]) * c[j];
            }
        }
        mi = min(mi, ans);
    }
    cout << mi;
}