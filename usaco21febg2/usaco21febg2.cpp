#include <bits/stdc++.h>
using namespace std;
const int MM = 303;
int n, dp[MM][MM], a[MM];
int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];  dp[i][i] = 1;
    }
    for(int len=1; len<n; len++){
        for(int l=1; l+len<=n; l++){
            int r = l + len;  dp[l][r] = 1e9;
            if(a[l] == a[r]) dp[l][r] = min(dp[l+1][r], dp[l][r-1]);
            for(int m=l; m<r; m++)
                dp[l][r] = min(dp[l][r], dp[l][m] + dp[m+1][r]);
        }
    }
    cout << dp[1][n] << endl;
}