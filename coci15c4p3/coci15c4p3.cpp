#include <bits/stdc++.h>
using namespace std;
const int mm = 1000 + 5;
int n, m[mm][mm];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        int ans = 0;
        for (int j = 0; j < n; j++) {
            ans |= m[i][j];
        }
        cout << ans << ' ';
    }
}