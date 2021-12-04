#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mm = 100000 + 5;
ll N, M, a[mm], fre[mm], bit[mm];
void update(ll x, ll v, ll arr[]) {
    while (x <= mm) {
        arr[x] += v;
        x += x & -x;
    }
}
ll query(ll x, ll arr[]) {
    ll sum = 0;
    while (x > 0) {
        sum += arr[x];
        x -= x & -x;
    }
    return sum;
}
int main() {
    cin >> N >> M;
    for (ll i = 1; i <= N; i++) { 
        cin >> a[i]; 
        update(i, a[i], bit); update(a[i], 1, fre);
    }
    for (ll i = 1; i <= M; i++) {
        char op; cin >> op;
        if (op == 'C') {
            ll x, v; cin >> x >> v;
            update(a[x], -1, fre); update(v, 1, fre); update(x, v - a[x], bit);
            a[x] = v;
        } else if (op == 'S') {
            ll l, r; cin >> l >> r;
            cout << query(r, bit) - query(l - 1, bit) << '\n';
        } else if (op == 'Q') {
            ll v; cin >> v;
            cout << query(v, fre) << '\n';
        }
    }
}