#include <bits/stdc++.h>
using namespace std;
const int mm = 500 + 5, mmm = 5000 * 500 / 2 + 1;
int t, n, breaks[mm], dp[mmm], out[mm];
bool vis[mm];
vector<int> x, y;
int main() {
    memset(dp, -1, sizeof dp);
    memset(vis, false, sizeof vis);
    cin >> t >> n;
    int sum = 0, halfsum;
    for (int i = 0; i < n; i++) {
        cin >> breaks[i]; sum += breaks[i];
    }
    halfsum = sum / 2;
    
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        int breakk = breaks[i];
        for (int j  = halfsum; j >= breakk; j--){ 
            if (dp[j] != -1) {
                continue;
            }
            if (dp[j - breakk] != -1) {
                dp[j] = i;
            }
        }
    }
    while(dp[halfsum] == -1) {
        halfsum--;
    }
    while(halfsum > 0) {
        int temp = dp[halfsum];
        vis[temp] = true;
        halfsum -= breaks[temp];
    }
    for (int i = 0; i < n; i++) (vis[i] ? x.push_back(i) : y.push_back(i));
    if(x.size() > 0) {
        out[x[0]] = 0;
        if (x.size() > 1) {
            for (int i = 1; i < x.size(); i++) {
                out[x[i]] = breaks[x[i - 1]] + out[x[i - 1]];
            }
        }
    }
    if (y.size() > 0) {
        out[y[0]] = 0;
        if (y.size() > 1) {
            for (int i = 1; i < y.size(); i++) {
                out[y[i]] = breaks[y[i - 1]] + out[y[i - 1]];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << out[i] << ' ';
    }
}