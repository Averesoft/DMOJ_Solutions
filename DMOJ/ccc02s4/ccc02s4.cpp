//CP Practice on DMOJ
#include <bits/stdc++.h>
using namespace std;
const int mm = 100 + 5;
int m, q;
string names[mm];
int times[mm];
int pre[mm];
int dp[mm];
vector<int> vc;
int main() {
    memset(dp, 0x3f3f3f3f, sizeof dp);
    cin >> m >> q;
    for (int i = 0; i < q; i++) {
        cin >> names[i];
        cin >> times[i];
    }
    dp[0] = 0;
    for (int i = 0; i < q; i++) {
        int temp = 0;
        for (int j = 0; j < m && i + j <= q; j++) {
            temp = max(temp, times[i+j]);
            int tempp = dp[i] + temp;
            if (tempp < dp[i+j+1]) {
                pre[i+j+1] = i;
                dp[i+j+1] = tempp;
            }
        }
    }
    cout << "Total Time: " << dp[q] << '\n';
    int idx;
    for (idx = q; idx > 0; idx = pre[idx]) {
        vc.push_back(idx);
    }
    vc.push_back(idx);
    reverse(vc.begin(), vc.end());
    for (int i = 0; i < vc.size()-1; i++) {
        for (int j = vc[i]; j < vc[i+1]; j++) {
            cout << names[j] << ' ';
        }
        cout << '\n';
    }
}