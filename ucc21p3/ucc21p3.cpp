#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mm = 10000000 + 5;
ll n, x, y, R, arr[mm];
int main() {
    cin >> n;
    cin >> x >> y;
    cin >> R;
    for (ll i = 0, l, r; i < R; i++) {
        cin >> l >> r;
        arr[l]++; arr[r + 1]--;
    }
    ll num = 0, sum = 0;
    for (ll i = 1; i <= n; i++) {
        num += arr[i];
        if (i >= x && i <= y) {
            sum += num;
        }
    }
    cout << sum;
}