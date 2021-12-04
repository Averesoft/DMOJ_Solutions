#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N;
set<ll> vc;
int main() {
    cin >> N;
    for (ll i = 1; i <= sqrt(N); i++) {
        if (N % i == 0) {
            ll j = N / i;
            vc.insert(i); vc.insert(j);
        }
    }
    for (ll u : vc) {
        cout << u << '\n';
    }
}