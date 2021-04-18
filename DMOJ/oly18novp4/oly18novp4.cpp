#include <bits/stdc++.h>
using namespace std;
const int mm = 1e5 + 5;
int n, m;
int sparse[mm][17], Log[mm];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.sync_with_stdio(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> sparse[i][0];
    }
    for (int i = 1; i < 17; i++) {
        for (int j = 0; j + (1 << i) <= n; j++) {
            sparse[j][i] = max(sparse[j][i - 1], sparse[j + (1 << (i - 1))][i - 1]);
        }
    }
    for (int i = 2; i <= n; i++) {
        Log[i] = Log[i / 2] + 1;
    }
    for (int i = 0, l, r; i < m; i++) {
        cin >> l >> r;
        cout << max(sparse[l - 1][Log[r - l + 1]], sparse[r - (1 << Log[r - l  + 1])][Log[r - l + 1]]) << '\n';
    }
}
//WHY DID I USE SEGTREE