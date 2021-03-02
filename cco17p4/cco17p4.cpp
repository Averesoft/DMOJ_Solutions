#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
const int mm = 501;
int n, h[mm]; bool dp[mm][50 * mm]; 
unordered_set<int> st;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    sort(h, h + n, greater<int>());
    dp[0][0] = true; int vol = h[0] * n;
    for (int i = 1; i < n; i++) {
        int cur = h[i]; 
        for (int j = 0; j <= vol; j++) {
            dp[i][j] = dp[i - 1][j];
        }
        for (int pre : st) {
            int dif = pre - cur;
            for (int j = 0; j <= vol - dif; j++) {
                if (dp[i-1][j]) {
                    dp[i][j + dif] = true;
                }
            }
        }
        st.insert(cur);
    }
    for (int j = 0; j <= vol; j++) {
        if (dp[n - 1][j]) {
            cout << j << ' ';
        }
    }
    cout << '\n';
}