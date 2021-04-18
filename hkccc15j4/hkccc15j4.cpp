#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int mm = 1e9+5;
int l, n;
vector<pii> vc;
int main() {
    cin >> l >> n;
    for (int i = 0; i < n; i ++) {
        int s, t; cin >> s >> t;
        vc.push_back({s, t});
    }
    sort(vc.begin(), vc.end());
    int ans = 0, ma = -1;
    for (pii u : vc) {
        ma = max(ma, u.first - ans);
        ans = max(ans, u.second);
    }
    ma = max(ma, l-ans);
    cout << ma;
}