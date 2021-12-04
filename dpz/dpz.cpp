#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mm = 2 * 1e5 + 5;
const int inf = 0x3f3f3f3f;
ll N, C, h[mm], dp[mm]; 
deque<int> dq;
double f(int j, int k) {
    return (double) (dp[k] + h[k] * h[k] - dp[j] - h[j] * h[j]) / (2 * (h[k] - h[j]));
}
int main() {
    memset(dp, inf, sizeof (dp));
    cin >> N >> C;
    for (int i = 1; i <= N; i++) {
        cin >> h[i];
    }
    dp[1] = 0; dq.push_back(1);
    for (int i = 2; i <= N; i++) {
        while(dq.size() >= 2 && f(dq[0], dq[1]) <= h[i]) {
            dq.pop_front();
        }
        dp[i] = dp[dq[0]] + (h[i] - h[dq[0]]) * (h[i] - h[dq[0]]) + C;
        while(dq.size() >= 2 && f(dq[dq.size() - 2], dq.back()) >= f(dq.back(), i)) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout << dp[N];
}