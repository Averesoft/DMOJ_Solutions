#include <bits/stdc++.h>
using namespace std;
const int mm = 2000 + 5;
int n, a[mm], b[mm], m;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; b[i] = a[i];
    }
    cin >> m;
    while(m--) {
        for (int i = 1; i <= n; i++) {
            b[i] += b[i - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << b[i] << ' ';
    }
}