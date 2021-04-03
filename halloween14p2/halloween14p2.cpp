//Cat Girls!
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const ll mm = 500000 + 5;
ll n, w, dp[mm];
vector<pll> vc;
int main() {
    cin >> n >> w;
    vc.push_back({0, 0});
    dp[0] = 0;
    for (ll t = 0, idx = 0; t < n; t++) {
        char ch; cin >> ch;
        if (ch == 'A') {
            ll p, c; cin >> p >> c;
            vc.push_back({p + vc.back().first, c + vc.back().second});
            dp[idx + 1] = max((ll)dp[idx], vc.back().second - lower_bound(vc.begin(), vc.end(), make_pair(vc.back().first - w, (ll)0)) -> second);
            idx++;
            cout << dp[idx] << '\n';
        } else {
            vc.pop_back();
            idx--;
        }
    }
}