#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int mm = 4 * 1e3 + 5, mmm = 1e9 + 1;
int n, a[mm];
unordered_map<int, bool> fre;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; fre[a[i]] = 1;
    }
    if (n == 2) {
        if ((a[1] + a[2]) % 2 == 0) {
            cout << 2; 
        } else {
            cout << 1;
        }
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if ((a[i] + a[j]) % 2 == 0 && fre[(a[i] + a[j]) / 2]) {
                cout << 3; return 0;
            }
        }
    }
    cout << 2;
}