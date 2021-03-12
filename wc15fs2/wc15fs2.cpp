#include <bits/stdc++.h>
using namespace std;
const int mm = 1e6+5;
int n, m, k, cow[mm], t[mm];
bool check(int lmt) {
    int cnt = 0;
    for (int i = 1, j = 1; j <= m; j++) {
        while (i <= n & t[j] <= cow[i] && t[j] >= cow[i] - k && cnt < lmt) {
            i++; cnt++;
        }
        cnt = 0;
        if (i > n) return true;
    }
    return false;
}
int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> cow[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> t[i];
    }
    sort(cow + 1, cow + n + 1);
    sort(t + 1, t + m + 1);
    int lo = 1, hi = n, ans = n+1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << (ans > n ? -1 : ans);
}