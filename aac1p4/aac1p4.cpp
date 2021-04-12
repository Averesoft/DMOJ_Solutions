#include <bits/stdc++.h>
using namespace std;
const int mm = 1e6 + 5;
int n, q, a[mm];
int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 0, l, r, x; i < q; i++) {
        cin >> l >> r >> x;
        bool flag = 0;
        for (int j = l; j <= r; j++) {
            for (int k = j + 1; k <= r; k++) {
                if (a[j] * a[k] == x && a[j] != a[k]) {
                    cout << "YES\n";
                    flag = 1;
                    break;
                }
            }
            if (flag) break;
        }
        if (!flag) {
            cout << "NO\n";
        }
    }
}