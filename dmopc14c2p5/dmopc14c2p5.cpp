#include <bits/stdc++.h>
using namespace std;
const int mm = 1000000 + 5;
int n, m; 
double dp[mm];
vector<int> adj[mm];
int main() {
    cin >> n >> m;
    for (int k = 1, i, j; k <= m; k++) {
        cin >> i >> j; adj[i].push_back(j);
    }
    dp[1] = 1;
    for (int i = 1; i <= n; i++) {
        if (adj[i].size()) {
            for (int t : adj[i]) {
                dp[t] += dp[i] / adj[i].size();
            }
        } else {
            printf("%.9f\n", dp[i]);
        }
    }
}