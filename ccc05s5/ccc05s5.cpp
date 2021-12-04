#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mm = 1e5 + 5;
int t, a[mm], bit[mm], tot; ll ans; map<int, int> mp;
void update(int idx, int val) {
    for (int i = idx; i <= t; i += i & -i) {
        bit[i] += val;
    }
}
int query(int idx) {
    int sum = 0;
    for (int i = idx; i > 0; i -= i & -i) {
        sum += bit[i];
    }
    return sum;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> a[i]; mp[a[i]] = 0;
    }
    for (auto &e: mp) {
        e.second = ++tot;
    }
    for (int i = 1; i <= t; i++) {
        int rk = mp[a[i]];
        ans += i - query(rk);
        update(rk, 1);
    }
    cout << fixed << setprecision(2) << (double) ans / t;
}