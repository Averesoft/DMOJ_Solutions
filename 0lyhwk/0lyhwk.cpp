#include <bits/stdc++.h>
using namespace std;
const int mm = 100 + 5, mmm = 8640 + 5;
int n, m, t, T[mm], empt = 0;
double v[mm], dp[mmm];
int main() {
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++) {
        cin >> T[i];
    }
    for (int i = 0, A; i < m; i++) {
        cin >> A;
        if (A == 0) {
            empt++;
        }
        for (int j = 0, x; j < A; j++) {
            cin >> x; v[x] += 1.0/A;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = t; j >= T[i]; j--) {
            dp[j] = max(dp[j], dp[j - T[i]] + v[i]);
        }
    }
    printf("%.2f", dp[t] + empt);
}
