#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mm = 10000 + 5;
ll N, S, T[mm], F[mm], dp[mm];
deque<ll> dq;
double f(ll j, ll k) {
    return (dp[j] - dp[k]) / (T[j] - T[k]);
}
int main() {
    cin >> N >> S;
    for (ll i = 1; i <= N; i++) {
        cin >> T[i] >> F[i];
    }
    for (ll i = N; i >= 1; i--) {
        T[i] += T[i + 1];
        F[i] += F[i + 1];
    }
    dq.push_back(N + 1);
    for (ll i = N; i >= 1; i--) {
        while (dq.size() >= 2 && f(dq[0], dq[1]) <= F[i]) {
            dq.pop_front();
        }
        dp[i] = dp[dq[0]] + (S + T[i] - T[dq[0]]) * F[i];
        while (dq.size() >= 2 && f(dq[dq.size() - 2], dq[dq.size() - 1]) >= f(dq[dq.size() - 1], i)) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout << dp[1];
}