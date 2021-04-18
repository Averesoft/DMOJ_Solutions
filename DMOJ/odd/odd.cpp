#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n; 
    int ans = 0;
    for (int i = 0, x; i < n; i++) {
        cin >> x; ans ^= x;
    }
    cout << ans << '\n';
}