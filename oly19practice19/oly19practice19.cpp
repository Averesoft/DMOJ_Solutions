#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mm = 1e6 + 6;
ll n, k, a[mm], moda[mm], ma = 0;
unordered_map<ll, ll> um;
int main() {
    cin >> n >> k;
    for (ll i = 0; i < n; i++) {
        cin >> a[i]; 
    }
    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        sum += a[i];
        moda[i] = (sum + k) % k;
    }
    for (ll i = 0; i < n; i++) {
        if (moda[i] == 0) {
            ma = i + 1;
        } else if (um.find(moda[i]) == um.end()) {
            um[moda[i]] = i;
        } else if (ma < i - um[moda[i]]) {
            ma = i - um[moda[i]];
        }
    }
    cout << ma;
}