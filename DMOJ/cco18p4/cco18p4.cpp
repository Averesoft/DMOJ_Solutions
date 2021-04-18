#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const ll INFIN = 10000000000;
ll r, c, k;
map<pii, ll> mp;
ll solve(ll a, ll b) {
    if (a < 1 ||  a > r || b < 1 || b > c) {
        return INFIN;
    }
    pii p = {a, b};
    if (mp.count(p)) {
        return mp[p];
    }
    cout << "? " << a << ' ' << b << '\n';
    cin >> mp[p]; return mp[p];
}
int main() {
    cin >> r >> c >> k;
    ll x1 = 1, y1 = 1, x2 = r+1, y2 = c+1;
    while(x1 < x2 || y1 < y2) {
        ll xm = (x1 + x2) / 2, ym = (y1 + y2) / 2;
        ll a = solve(xm, ym), b = solve(xm + 1, ym), c = solve(xm, ym + 1);
        if (a < b) {
            x2 = xm;
        } else {
            x1 = xm + 1;
        }
        if (a < c) {
            y2 = ym;
        } else {
            y1 = ym + 1;
        }
    }
    cout << "! " << solve(x1, y1) << '\n';
    return 0;
}