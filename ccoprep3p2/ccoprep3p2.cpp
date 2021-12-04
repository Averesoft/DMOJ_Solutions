#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mm = 2 * 1e6 + 5;
int N, L, q[mm], f, r; ll psa[mm], dp[mm];
double slope(int j, int k) {
    return (double) (dp[j] + psa[j] * psa[j] - dp[k] - psa[k] * psa[k]) / (2 * (psa[j] - psa[k]));
}
int main() {
    cin >> N >> L; L++;
    for (int i = 1; i <= N; i++) {
        cin >> psa[i]; psa[i]++;
        psa[i] += psa[i - 1];
    }
    memset(dp, 0x3f, sizeof (dp)); dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        while (f < r && slope(q[f], q[f + 1]) >= psa[i] - L) f++;
        dp[i] = dp[q[f]] + (psa[i] - psa[q[f]] - L) * (psa[i] - psa[q[f]] - L);
        while (f < r && slope(q[r - 1], q[r]) <= slope(q[r], i)) r--;
        q[++r] = i;
    }
    cout << dp[N];
}