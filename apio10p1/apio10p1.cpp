#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mm = 1000000 + 5;
ll n, a, b, c, x[mm], psa[mm], dp[mm];
deque<int> dq;
ll quad(ll i, ll j) {
    return (double) (dp[j] - dp[i] + b * (psa[i] - psa[j]) + a * (psa[j] * psa[j] - psa[i] * psa[i])) / (2 * a * (psa[j] - psa[i]));
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dp, -0x3f3f3f3f, sizeof (dp));
    cin >> n;
    cin >> a >> b >> c;
    for (ll i = 1; i <= n; i++) {
        cin >> x[i]; psa[i] = x[i] + psa[i - 1];
    }
    dp[0] = 0; dq.push_back(0);
    for (ll i = 1; i <= n; i++) {
        while(dq.size() >= 2 && quad(dq[0], dq[1]) <= psa[i]) {
            dq.pop_front();
        }
        dp[i] = dp[dq[0]] + a * (psa[i] - psa[dq[0]]) * (psa[i] - psa[dq[0]]) + b * (psa[i] - psa[dq[0]]) + c;
        while(dq.size() >= 2 && quad(dq[dq.size() - 2], dq.back()) >= quad(dq.back(), i)) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout << dp[n];
}
//cheesed solution (or at least i think its cheesed), lets solve this for real
/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mm = 1000000 + 5;
ll n, a, b, c, x[mm], psa[mm], dp[mm];
ll quad(ll i, ll j) {
    return a * (psa[j] - psa[i - 1]) * (psa[j] - psa[i - 1]) + b * (psa[j] - psa[i - 1]) + c;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dp, -0x3f3f3f3f, sizeof (dp));
    cin >> n;
    cin >> a >> b >> c;
    for (ll i = 1; i <= n; i++) {
        cin >> x[i]; psa[i] = x[i] + psa[i - 1];
    }
    int last = 0; dp[0] = 0;
    for (ll i = 1; i <= n; i++) {
        for (ll k = last; k < i; k++) {
            ll tmp = dp[k] + quad(k + 1, i);
            if (tmp > dp[i]) {
                dp[i] = tmp; last = k; 
            }
        }
    }
    cout << dp[n];
}
*/