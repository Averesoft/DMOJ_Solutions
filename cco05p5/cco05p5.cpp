#include <bits/stdc++.h>
using namespace std;
const int mm = 20000 + 5;
int n, a[mm], b[mm], c[mm], d[mm]; 
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    c[0] = (b[0] - 1) + (b[0] - a[0]);
    d[0] = (b[0] - 1);
    for (int i = 1; i < n; i++) {
        d[i] = b[i] - a[i] + min(c[i - 1] + abs(a[i] - a[i - 1]), d[i - 1] + abs(a[i] - b[i - 1]));
        c[i] = b[i] - a[i] + min(d[i - 1] + abs(b[i] - b[i - 1]), c[i - 1] + abs(b[i] - a[i - 1]));
    }
    cout << min(n - b[n - 1] + d[n - 1], n - a[n - 1] + c[n - 1]) + n - 1;
}