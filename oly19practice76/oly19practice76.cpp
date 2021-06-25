#include <bits/stdc++.h>
using namespace std;
const int mm = 20 + 1;
int n, v[mm], a = 0, b = 0, c = 0;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    sort(v + 1, v + 1 + n);
    for (int i = 1; i <= n; i++) {
        if (a <= b && a <= c) {
            a += v[i];
        } else if (b <= a && b <= c) {
            b += v[i];
        } else if (c <= a && c <= b) {
            c += v[i];
        }
    }
    cout << max(a, max(b, c));
}