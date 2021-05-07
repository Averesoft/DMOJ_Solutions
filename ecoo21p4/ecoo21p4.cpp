#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mm = 1e5 + 5;
ll k, factor[mm], sum = 0;
vector<ll> primes, vc, candy;
int main() {
    cin >> k; k++;
    for (ll i = 2; i * i < mm; i++) {
        if (factor[i] == 0) {
            for (ll j = i * i; j < mm; j += i) {
                factor[j] = i;
            }
        }
    }
    for (ll i = 2; i < mm; i++) {
        if (factor[i] == 0) primes.push_back(i);
    }
    for (ll i = 0; i < primes.size(); i++) {
        while (k % primes[i] == 0) {
            vc.push_back(primes[i]); k /= primes[i];
        }
    }
    if (k > 1) vc.push_back(k);
    for (ll i = 0; i < vc.size(); i++) {
        sum += vc[i] - 1;
    }
    if (sum > 100000) { cout << "Sad Chris" << '\n'; return 0; }
    for (ll i = 0; i < (ll) vc.size(); i++) {
        for (ll j = 0; j < vc[i] - 1; j++) {
            candy.push_back(i);
        }
    }
    cout << sum << '\n';
    for (ll i = 0; i < sum; i++) {
        cout << candy[i] + 1 << ' ';
    }
}