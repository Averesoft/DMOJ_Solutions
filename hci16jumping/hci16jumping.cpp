#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mm = 2000 + 5;
ll N, C, dp[mm][mm], ans = LLONG_MAX;
bool grid[mm][mm];
deque<ll> dq;
long double f(ll i, ll j, ll k) {
    return (long double) (dp[j][k - 1] - dp[i][k - 1] + (j * j) - (i * i)) / (long double) (2 * (j - i));
}
int main() {
    cin >> N >> C;
    for (ll i = 0; i < C; i++) {
        for (ll j = 0; j < N; j++) {
            char ch; cin >> ch;
            if (ch == '1') {
                grid[i][j] = 1;
            } else if (ch == '0') {
                grid[i][j] = 0;
            }
        }
    }
    for (ll i = 0; i < C; i++){ 
        if (grid[i][0]) {
            dp[i][0] = 0; dq.push_back(i);
        } else {
            dp[i][0] = 0x3f3f3f3f;
        }
    }
    for (ll j = 1; j < N; j++) {
        deque<ll> temp;
        for (ll i = 0; i < C; i++) {
            if (!grid[i][j]) {
                dp[i][j] = 0x3f3f3f3f; continue;
            }
            while (dq.size() >= 2 && f(dq[0], dq[1], j) <= (long double) i) {
                dq.pop_front();
            }
            dp[i][j] = dp[dq[0]][j - 1] + ((ll) i - dq[0]) * ((ll) i - dq[0]);
            while (temp.size() >= 2 && f(temp[temp.size() - 2], temp[temp.size() - 1], j + 1) > f(temp[temp.size() - 1], i, j + 1)) {
                temp.pop_back();
            }
            temp.push_back(i);
        }
        dq = temp;
    }
    for (ll i = 0; i < C; i++) {
        if (grid[i][N - 1] && dp[i][N - 1] < ans) {
            ans = dp[i][N - 1];
        }
    }
    cout << ans;
}