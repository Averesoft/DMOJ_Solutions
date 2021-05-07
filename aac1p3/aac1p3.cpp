#include <bits/stdc++.h>
using namespace std;
const int mm = 1e6 + 5;
int n, x, a[mm];
int main() {
    cin >> n >> x;
    if ((n - x) % 2 != 0) {
        cout << -1 << '\n';
        return 0;
    }
    int idx = 0;
    for (int i = 0; i < (n - x) / 2; i++) {
        a[idx]++; idx += 2;
    }
    for (int i = 0; i < n; i++) {
        cout << a[i];
        if (i != n - 1) {
            cout << ' ';
        }
    }
    cout << '\n';
}