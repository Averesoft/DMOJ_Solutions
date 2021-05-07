#include <bits/stdc++.h>
using namespace std;
int n, m, res, a[51], dp[1<<20], key[1<<20], pre[1<<20]; char ch;
int main(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        res <<= 1;
        for(int j=1; j<=m; j++) {
            cin >> ch;
            a[j] = a[j] << 1 | (ch == 'X');
            res = res | (ch == 'X');
        }
    }
    if(res == 0) { cout << 1 << "\n" << 1 << "\n"; return 0;}
    memset(dp, 0x3f, sizeof(dp)); dp[0] = 0;
    for(int i=1; i<=m; i++) {
        for(int mask = 0; mask < 1<<n; mask++){
            int nmask = mask | a[i];
            if(dp[nmask] > dp[mask] + 1) {
                dp[nmask] = dp[mask] + 1;
                key[nmask] = i; pre[nmask] = mask;
            }
        }
    }
    cout << dp[res] << endl;
    for(int cur=res; cur!=0; cur=pre[cur])
        cout << key[cur] << " ";
    cout << endl;
}