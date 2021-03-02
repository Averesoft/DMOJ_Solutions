#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int mm = 1e9+5;
int l, n;
bool arr[mm];
int main() {
    memset(arr, false, sizeof arr);
    cin >> l >> n;
    for (int i = 0; i < n; i ++) {
        int s, t; cin >> s >> t;
        for (int j = s; j < t; j++) {
            arr[j] = true;
        }
    }
    int ans = 0;
    for (int i = 0; i < l; i++) {
        if (!arr[i]) {
            ans++;
        }
    }
    cout << ans;
}