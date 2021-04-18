#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mm = 5000 + 5;
int n, q, bit[mm][mm];
void update(int x, int y, int v) {
    for (int i = x; i <= n; i += i & -i) {
        for (int j = y; j <= n; j += j & -j) {
            bit[i][j] += v;
        }
    }
}
int query(int x, int y) {
    ll sum = 0;
    for (int i = x; i; i -= i & -i) {
        for (int j = y; j; j -= j & -j) {
            sum += bit[i][j];
        }
    }
    return sum;
}
int main() {
    cin >> n >> q;
    for (int i = 0; i < q; i++) {
        char ch; cin >> ch;
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        if (ch == 'U') {
            int v; cin >> v;
            update(x1, y1, v); update(x2 + 1, y1, -v); 
            update(x1, y2 + 1, -v); update(x2 + 1, y2 + 1, v);
        } else if (ch == 'Q') {
            ll ans = 0;
            for (int i = x1; i <= x2; i++) {
                for (int j = y1; j <= y2; j++) {
                    ans += query(i, j);
                }
            }
            cout << ans << '\n';
        }
    }
}