#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mm = 2 * 1e5 + 5;
ll n, d, k, h[mm];
int main() {
    cin >> n >> d >> k;
    for (ll i = 1; i <= n; i++) {
        cin >> h[i];
    }
    sort(h + 1, h + n + 1);
    ll sum = 0;
    for (ll i = 1; i <= n - k; i++) {
        sum += ceil(((double)h[i] / d));
    }
    cout << sum;
}