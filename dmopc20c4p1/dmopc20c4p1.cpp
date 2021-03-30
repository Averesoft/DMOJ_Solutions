#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll n, s; cin >> n >> s;
    ll sum = n*(n + 1) / 2;
    double diff = sum - s;
    ll out = ceil(diff/2.0) - 1;
    int a, b;
    a = ceil(diff/2.0) - 1; b = floor(diff/2.0) + 1;
    if (a > n - b) {
        out -= a - (n - b + 1);
    }
    cout << out << '\n';
}
int main() {
    ll t; cin >> t;
    for (ll i = 0; i < t; i++) {
        solve();
    }
}