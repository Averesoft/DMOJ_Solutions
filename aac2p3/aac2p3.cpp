//WHY IS IT SO HARD FOR SJAY TO REACH SAM AHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
//WHAT IS WRONG WITH MY CODE 😩😩😩😩😩eeeee
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const ll mm = 1500 + 5;
ll n, m, dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1}, psa[mm][mm], psa1[mm][mm];
bool a[mm][mm], vis[mm][mm];
bool kekw(ll l, ll r, ll x) {
    for (int i = l; i <= l - x + 1; i++) {
        if (psa[i][r + x - 1] - psa[i][r - 1] != 0) {
            return 0;
        }
    }
    return l >= 1 && l <= n - x + 1 && r >= 1 && r <= m - x + 1;
}
bool chck(ll x) {
    memset(vis, 0, sizeof (vis));
    queue<pii> q; q.push({1, 1}); vis[1][1] = 1;
    while(!q.empty()) {
        pii cell = q.front(); q.pop();
        if (cell.first == n - x + 1 && cell.second == m - x + 1 && kekw(cell.first, cell.second, x)) {
            return 1;
        }
        for (ll i = 0; i < 4; i++) {
            if (kekw(cell.first + dx[i], cell.second + dy[i], x) && !vis[cell.first + dx[i]][cell.second + dy[i]]) {
                q.push({cell.first + dx[i], cell.second + dy[i]});
                vis[cell.first + dx[i]][cell.second + dy[i]] = 1;
            }
        }
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            char ch; cin >> ch; a[i][j] = (ch == 'O' ? 1 : 0);
            psa[i][j] = !a[i][j]; psa[i][j] += psa[i][j - 1]; 
        }
    }
    ll lo = 0, hi = n;
    int idx = 0;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        //cout << lo << mid << hi << ' ' << idx << '\n'; idx++;
        if (chck(mid)) {
            if (chck(mid + 1)) {
                lo = mid + 1;
            } else {
                cout << mid; return 0;
            }
        } else {
            hi = mid;
        }
    }
    cout << 0;
}