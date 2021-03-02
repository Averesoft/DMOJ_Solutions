#include <bits/stdc++.h>
using namespace std;
const int mm = 1e6 + 5;
int a[mm], dp[mm];
int kekw(int l, int r, int key) {
    while(r -l > 1) {
        int m = l + (r-l)/2;
        if (dp[m] >= key) {
            r = m;
        } else {
            l = m;
        }
    }
    return r;
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.sync_with_stdio(0);
    cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    dp[0] = a[0];
    int length = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] < dp[0]) {
            dp[0] = a[i];
        } else if (a[i] > dp[length-1]) {
            dp[length++] = a[i];
        } else {
            dp[kekw(-1, length-1, a[i])] = a[i];
        } 
    }
    cout << length;
    
}