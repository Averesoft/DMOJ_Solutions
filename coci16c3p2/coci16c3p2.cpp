#include <bits/stdc++.h>
using namespace std;
const int mm = 2000 + 5;
int N, M;
char A[mm][mm];
string dp[mm][mm];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> A[i][j];
        }
    }
    dp[1][1] = A[1][1];
    for (int i = 2; i <= N; i++) {
        dp[i][1] = dp[i - 1][1] + A[i][1];
    }
    for (int j = 2; j <= M; j++) {
        dp[1][j] = dp[1][j - 1] + A[1][j];
    }
    for (int i = 2; i <= N; i++) {
        for (int j = 2; j <= M; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + A[i][j];
        }
    }
    cout << dp[N][M] << '\n';
}