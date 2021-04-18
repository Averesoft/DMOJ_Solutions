#include <bits/stdc++.h>
using namespace std;
const int MM = 1.5e5 + 5;
struct node { int l, r, g; } seg[4 * MM];
int N, M, a[MM], dif[MM][17], x[MM], y[MM], z[MM];
void build(int l, int r, int rt) {
    seg[rt].l = l; seg[rt].r = r;
    if (l == r) { seg[rt].g = a[l]; return; }
    int mid = (l + r) / 2;
    build(l, mid, 2 * rt); build(mid + 1, r, 2 * rt + 1);
    seg[rt].g = __gcd(seg[2 * rt].g, seg[2 * rt + 1].g);
}
int query(int l, int r, int rt) {
    if (seg[rt].l == l && seg[rt].r == r) return seg[rt].g;
    int mid = (seg[rt].l + seg[rt].r) / 2;
    if (r <= mid) return query(l, r, 2 * rt);
    if (l > mid) return query(l, r, 2 * rt + 1);
    return __gcd(query(l, mid, 2 * rt), query(mid + 1, r, 2 * rt + 1));
}
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> x[i] >> y[i] >> z[i];
        dif[x[i]][z[i]]++; dif[y[i] + 1][z[i]]--;
    }
    for (int i = 1; i <= N; i++) {
        int lcm = 1;
        for (int j = 1; j <= 16; j++) {
            dif[i][j] += dif[i - 1][j];
            if (dif[i][j] > 0) lcm = lcm * j / __gcd(lcm, j);
        }
        a[i] = lcm;
    }
    build(1, N, 1);
    for (int i = 1; i <= M; i++) {
        if (query(x[i], y[i], 1) != z[i]) {
            cout << "Impossible\n"; 
            return 0;
        }
    }
    for (int i = 1; i <= N; i++)
        cout << a[i] << " ";
    cout << '\n';
}