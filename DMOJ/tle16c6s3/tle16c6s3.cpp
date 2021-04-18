#include <bits/stdc++.h>
using namespace std;
const int mm = 2000 + 5;
struct E{int x, d; } a[mm];
int n, dp[2][mm][mm], sum[mm], ans = 0;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &a[i].x, &a[i].d);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {

    }
}
