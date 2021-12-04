#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mm = 1e6 + 5;
ll N, H, P, A[mm], psa[mm];
int main() {
    cin >> N >> H >> P;
    for (ll i = 1; i <= N; i++) {
        cin >> A[i];
    }
    sort(A, A + 1 + N);
    for (ll i = 1; i <= N; i++) {
        psa[i] = psa[i - 1] + A[i];
    }
    ll ans = psa[N] * P;
    for (ll i = N; i >= 1; i--) {
        ans = min((H - P * (N - i)) * A[i] + P * (psa[N] - psa[i]), ans);
    }
    cout << ans << '\n';
}