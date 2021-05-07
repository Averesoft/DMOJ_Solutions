#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mm = 1e5 + 5;
int n, k, l, a[mm];
bool check(int x) {
    ll area = 0;
    for (int i = n - 1; i >= n - x; i--) {
        if (a[i] < x) area += x - a[i];
        if (a[i] + k < x) return 0;
    }
    return area <= (ll) k * l;
}
int main() {
    cin >> n >> k >> l;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int lo = 0, hi = n, ans = 0;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) { lo = mid + 1; ans = mid; }
        else hi = mid - 1;
    }
    cout << ans << '\n';
}