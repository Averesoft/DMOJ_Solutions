//memoize more like memorize 👉👈
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int mm = 70 + 5, inf = 0x3f3f3f3f;
struct node {
    int key, weight, fre;
} a[mm];
bool cmp_key(node a, node b) {
    return a.key < b.key;
}
bool cmp_weight(node a, node b) {
    return a.weight < b.weight;
}
int n, k, sum[mm], dp[mm][mm][mm];
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].key;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i].weight;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i].fre;
    }
    sort(a + 1, a + n + 1, cmp_weight);
    for (int i = 1; i <= n; i++) {
        a[i].weight = i;
    }
    sort(a + 1, a + n + 1, cmp_key);
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i].fre;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i].weight >= j) {
                dp[i][i][j] = a[i].fre;
            } else {
                dp[i][i][j] = a[i].fre + k;
            }
        }
    }
    for (int w = n; w >= 1; w--) {
        for (int t = 1; t < n; t++) {
            for (int i = 1; i + t <= n; i++) {
                int j = i + t, s = inf;
                for (int kk = i; kk <= j; kk++) {
                    s = min(s, dp[i][kk - 1][w] + dp[kk + 1][j][w] + sum[j] - sum[i - 1] + k);
                    if (a[kk].weight >= w) {
                        s = min(s, dp[i][kk - 1][a[kk].weight] + dp[kk + 1][j][a[kk].weight] + sum[j] - sum[i - 1]);
                    }
                }
                dp[i][j][w] = s;
            }
        }
    }
    cout << dp[1][n][1];
}