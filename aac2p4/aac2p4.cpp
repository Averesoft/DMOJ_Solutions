#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mm = 600 + 5;
ll n, a[mm];
void solve() {
    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    deque<ll> b;
    do {
        b.clear();
        for (ll i = 0; i < n; i++) {
            b.push_back(a[i]);
        }
        ll suma = 0, sumb = 0;
        while(b.size() > 1) {
            if (b.front() > b.back()) {
                suma += b.front(); b.pop_front();
            } else if (b.front() <= b.back()) {
                suma += b.back(); b.pop_back();
            } 
            if (b.front() > b.back()) {
                sumb += b.front(); b.pop_front();
            } else if (b.front() <= b.back()) {
                sumb += b.back(); b.pop_back();
            } 
        }
        if (b.size() == 1) {
            suma += b.front(); b.pop_front();
        }
        if (suma > sumb) {
            for (ll i = 0; i < n; i++) {
                cout << a[i];
                if (i != n - 1) cout << ' ';
            }
            cout << '\n';
            return;
        }
    } while(next_permutation(a, a + n));
    cout << -1 << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t; cin >> t;
    while(t--) {
        solve();
    }
}