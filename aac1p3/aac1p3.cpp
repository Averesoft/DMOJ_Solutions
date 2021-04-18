#include <bits/stdc++.h>
using namespace std;
const int mm = 1e6 + 5;
int n, x, a[mm];
int main() {
    cin >> n >> x;
    if (x == n - 1) {
        cout << -1;
        return 0;
    }
    for (int i = 1; i <= n - x - 1; i++) {
        a[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i];
        if (i != n) {
            cout << ' ';
        }
    }
    cout << '\n';
}