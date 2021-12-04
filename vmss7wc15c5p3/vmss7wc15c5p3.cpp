#include <bits/stdc++.h>
using namespace std;
const int mm = 2000 + 5, mod = 1e9 + 7;
int N, BIT[mm][mm], ans = 0;
void update(int r, int c, int t) {
    for (int i = c; i <= r + c; i += i & -i) {
        BIT[r + c][i] += t; BIT[r + c][i] %= mod;
    }
}
int sheeesh(int r, int c) {
    int ret = 0;
    for (int i = c; i > 0; i -= i & -i) {
        ret += BIT[r + c][i]; ret %= mod;
    }
    return ret;
}
int sheesh(int r, int c, int x) {
    return (sheeesh(r - x, c + x) - sheeesh(r + 1, c - 1) + mod) % mod;
}
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int op; cin >> op;
        if (op == 1) {
            int r, c, t; cin >> r >> c >> t;
            update(r, c, t);
        } else if (op == 2) {
            int r, c, x; cin >> r >> c >> x;
            ans += sheesh(r, c, x); ans %= mod;
        }
    }
    cout << ans;
}