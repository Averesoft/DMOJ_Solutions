#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mm = 200000 + 5;
ll n, q, a[mm], v[mm], l[mm], r[mm], seg[mm];
void update(int i, int a) {
    i += n; seg[i] = a;
    for (int i = i / 2; i >= 1; i /= 2) {
        seg[i] = min(seg[i * 2], seg[i * 2 + 1]);
    }
}
int query(int v, int x, int y) {
    int l = x, r = y;
    l += x; r += y;
    while (l < r) {
        if (l % 2 == 1) {

        }
        if (r % 2 == 1) {
            
        }
    }
}
int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; update(i, a[i]);
    }
    for (int i = 1, v, l, r; i <= q; i++) {
        cin >> v >> l >> r;
        
    }

}