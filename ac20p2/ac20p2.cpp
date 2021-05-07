#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mm = 1e5 + 5;
ll n, q, a[mm], fre[mm];
int main() {
    cin >> n >> q;
    for (ll i = 0; i < n; i++) {
        cin >> a[i]; fre[a[i]]++;
    }
    for (ll i = 0; i < q; i++) {
        ll num, v; cin >> num >> v;
        if (num == 1) {
            fre[v / 2] += fre[v];
            fre[(v + 1) / 2] += fre[v];
            fre[v] = 0;
        } else if (num == 2) {
            cout << fre[v] << '\n';
        }
    }
}