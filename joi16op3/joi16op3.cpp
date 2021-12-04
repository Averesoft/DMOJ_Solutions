#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
int N, L, a[102]; ll dp[102][102][1002][3], ans;
void add(ll &x, ll y) {
    x += y;
    if (x >= mod) x -= mod;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> L;
    if (N == 1) { cout << 1; return 0; }
    for (int i = 1; i <= N; i++) cin >> a[i];
    sort(a + 1, a + N + 1);
    a[0] = a[1]; dp[0][0][0][0] = 1;
    for (int i = 0; i < N; i++) { //# of buildings
        for (int j = 0; j <= i; j++) { //# of components
            for (int k = 0; k <= L; k++) { //sum o diff
                for (int p = 0; p < 3; p++) { //# of beginning or ending points (0/1/2) 
                    int w = k + (a[i + 1] - a[i]) * (2 * j - p); ll pre = dp[i][j][k][p];
                    if (!pre || w > L) continue;
                    add(dp[i + 1][j + 1][w][p], pre * (j + 1 - p) % mod); //case 1: make a[i] as a new component
                    if (j >= 1) add(dp[i + 1][j - 1][w][p], pre * (j - 1) % mod); //case 2: join two components
                    add(dp[i + 1][j][w][p], pre * (2 * j - p) % mod); //case 3: add it into one component
                    if (p < 2) {
                        add(dp[i + 1][j + 1][w][p + 1], pre * (2 - p) % mod); //case 4: create a new component and use it as beginning or ending
                        if (j > 0) add(dp[i + 1][j][w][p + 1], pre * (2 - p) % mod); //case 5: add it into the beginning or ending component
                    }
                }
            }
        }
    }
    for (int i = 0; i <= L; i++) add(ans, dp[N][1][i][2]);
    cout << ans;
}
