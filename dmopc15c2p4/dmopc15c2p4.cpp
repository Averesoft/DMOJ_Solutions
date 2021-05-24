#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mm = 1e5 + 5;
ll n, r[mm], l[mm], h[mm], dp[mm];
int main() {
    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> r[i] >> l[i] >> h[i];
    }
    for (ll i = n - 1; i >= 0; i--) {
        ll lo = 0, hi = n;
        while(lo < hi) {
            ll mid = (lo + hi) / 2;
            if (r[mid] >= r[i] + l[i]) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        dp[i] = max(h[i] + dp[lo], dp[i + 1]);
    }
    cout << dp[0];
}