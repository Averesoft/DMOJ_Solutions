#include <bits/stdc++.h>
using namespace std;
const int mm = 2 * 1e5 + 5;
int n, b[mm], ans = 0;
bool vis[mm];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        memset(vis, 0, sizeof vis);
        for (int j = i - 1; j >= 0; j--) {
            if (b[i] == b[j]) {
                break;
            }
            if (!vis[b[j]]) {
                vis[b[j]] = 1; ans++; 
            } 
        }
    }
    cout << ans;
}