#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const ll mm = 1e6 + 5;
ll n, m, divi, x = 1, y = 1;
double slope;
vector<pll> vc;
bool cmp(ll x, ll y) {
    ll a = (ll) n * (y - 1), b = (ll) n * y;
    return a < x * m && b > (x - 1) * m;
}
ll gcd(ll a, ll b) {
    return (b == 0 ? a : gcd(b, a % b));
}
int main() {
    cin >> n >> m;
    divi = gcd(n, m);
    n /= divi; m /= divi;
    while(x <= n && y <= m) {
        vc.push_back({x, y});
        ((x + 1 <= n && cmp(x + 1, y)) ? x++ : y++);
    }
    cout << vc.size() * divi << '\n';
    for (ll i = 0; i < divi; i++) {
        for (ll j = 0; j < vc.size(); j++) {
            cout << vc[j].first + i * n << ' ' << vc[j].second + i * m << '\n';
        }
    }
}