#include <bits/stdc++.h>
using namespace std;
const int mm = 2 * 1e5 + 5;
int n, a[mm], b[mm]; //dp[mm][mm];
int main() {
    cin >> n;
    int cnt = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; 
        if (a[i] == cnt) {
            cnt++;
        }
    }
    cout << (cnt == 1 ? -1 : n - cnt + 1);
}