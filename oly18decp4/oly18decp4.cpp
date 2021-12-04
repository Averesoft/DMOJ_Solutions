#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mm = 1e5 + 5;
ll N, M, a[mm];
int main() {
    cin >> N >> M;
    for (ll i = 1; i <= N; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + N);
    ll lo = 1, hi = N, ans = 0;
    while (lo < hi) {
        if (a[lo] + a[hi] <= M) {
            ans += hi - lo; lo++;
        } else {
            hi--;
        }
    }
    cout << ans;
}