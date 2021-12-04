#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int mm = 5000 + 5;
int N, K, v[mm], idx[mm], dp[mm], cnt = 1, ma = -1;
pii a[mm];
int main() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> v[i]; a[i] = {v[i], i};
    }
    sort(a + 1, a + N + 1);
    for (int i = 1; i <= N; i++) {
        idx[a[i].second] = cnt;
        if (i % K == 0) {
            cnt++;
        }
    }
    for (int i = 1; i <= N; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++) {
            if (idx[i] >= idx[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ma = max(ma, dp[i]);
    }
    cout << N - ma;
}