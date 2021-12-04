#include <bits/stdc++.h>
using namespace std;
const int mm = 1e6 + 5, mmm = 200 + 5;
int n, k, psa[mm], dp[mm][mmm];
deque <int> dq;
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> psa[i];
        psa[i] += psa[i - 1];
    }
    for (int K = 1; K <= k; K++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i][K] = max(dp[i][K], dp[j][K - 1] + (psa[i] - psa[j]) * (psa[n] - psa[i]));
            }
        }
    }
    cout << dp[n][k];
}
/**
#include <bits/stdc++.h>
using namespace std;
const int mm = 1e6 + 5, mmm = 200 + 5;
int n, k, psa[mm], dp[mm][mmm];
deque <int> dq;
double f(int j, int p, int K) {
    return (double) (dp[j][K] - psa[n] * psa[j] - dp[p][K] + psa[n] * psa[p]) / (psa[p] - psa[j]);
}
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> psa[i];
        psa[i] += psa[i - 1];
    }
    for (int K = 1; K <= k; K++) {
        for (int i = 1; i <= n; i++) {
            while(dq.size() >= 2 && f(dq[dq.size() - 1], dq[dq.size() - 2], K) >= f(dq[dq.size() - 2], i, K)) {
                dq.pop_back();
            }
            
            dq.push_back(i); 
        }
        dq.clear();
    }
        
} 

*/