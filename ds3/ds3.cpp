#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mm = 1e5 + 5;
ll a[mm], gre[mm*2], mini[mm*2];
ll n, m;
ll greatest(ll a, ll b) {
    return b == 0 ? a : greatest(b, a % b);
}
void construct() {
    for (ll i = 1; i <= n; i++) {
        mini[i + n] = a[i];
    }
    for (ll i = n - 1; i >= 1; i--) {
        mini[i] = min(mini[2 * i], mini[2 * i + 1]);
    }
    for (ll i = 1; i <= n; i++) {
        gre[i + n] = a[i];
    }
    for (ll i = n - 1; i >= 1; i--) {
        gre[i] = greatest(gre[2 * i], gre[2 * i + 1]);
    }
}
void update(ll x, ll v) {
    ll temp = x;
    x = x + n;
    mini[x] = v;
    while (x > 1) {
        x /= 2;
        mini[x] = min(mini[x * 2], mini[x * 2 + 1]);
    }
    x = temp;
    x = x + n;
    gre[x] = v;
    while (x > 1) {
        x /= 2;
        gre[x] = greatest(gre[x * 2], gre[x * 2 + 1]);
    }
}
ll minimum(ll l, ll r) {
    l += n; r += n;
    ll minimum = LLONG_MAX;
    while (l < r) {
        if (l % 2 == 1) {
            minimum = min(minimum, mini[l]);
            l++;
        } 
        if (r % 2 == 1) {
            r--;
            minimum = min(minimum, mini[r]);
        }
        l /= 2; r /= 2;
    }
    return minimum;
}
ll gcd(ll l, ll r) {
    l += n; r += n;
    ll great = gre[l];
    while (l < r) {
        if (l % 2 == 1) {
            great = greatest(great, gre[l]);
            l++;
        }
        if (r % 2 == 1) {
            r--;
            great = greatest(great, gre[r]);
        }
        l /= 2; r /= 2;
    }
    return great;
}
ll same(ll l, ll r, ll g) {
    ll count = 0;
    for (ll i = l; i <= r; i++) {
        if (a[i] == g) {
            count++;
        }
    }
    return count;
}
int main()
{
    cin >> n >> m;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    construct();
    ll g;
    for (ll i = 1; i <= m; i++) {
        char ch; cin >> ch;
        if (ch == 'C') {
            ll x, v; cin >> x >> v;
            a[x] = v;
            update(x, v);
        }
        else if (ch == 'M') {
            ll l, r; cin >> l >> r;
            cout << minimum(l, r+1) << '\n';
        }
        else if (ch == 'G') {
            ll l, r; cin >> l >> r;
            cout << gcd(l, r+1) << '\n';
        }
        else if (ch == 'Q') {
            ll l, r; cin >> l >> r;
            ll g = gcd(l, r+1);
            cout << same(l, r+1, g) << '\n';
        }
    }
}