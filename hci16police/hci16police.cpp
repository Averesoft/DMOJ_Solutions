#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mm = 1000000 + 5;
ll N, H, pos[mm], dp[mm];
int main() {
    cin >> N >> H;
    for (int i = 1; i <= N; i++) {
        cin >> pos[i];
    }
    ll last = 0; 
    for (int a = 1; a <= N; a++) {
        dp[a] = 0x3f3f3f3f;
        for (int b = last; b < a; b++) {
            ll tmp = dp[b] + (pos[a] - pos[b + 1]) * (pos[a] - pos[b + 1]) + H;
            if (dp[a] > tmp) {
                dp[a] = tmp; last = b;
            }
        }
    }
    cout << dp[N];
}