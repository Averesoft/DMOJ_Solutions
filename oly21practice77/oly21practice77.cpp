#include <bits/stdc++.h>
using namespace std;
const int mm = 50 + 5;
typedef long long ll;
int N, X, a, sum; ll dp[mm][mm*mm], nas;
int main() {
    cin >> N >> X; dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        cin >> a; sum += a;
        for (int j = i; j >= 1; j--) {
            for (int k = a; k <= sum; k++) {
                dp[j][k] += dp[j - 1][k - a];
            }
        }
    }
    cout << dp[N][sum];
}