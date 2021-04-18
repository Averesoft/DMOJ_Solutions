#include <bits/stdc++.h>
using namespace std;
const int mm = 65536 + 5;
bool two[mm];
int main() {
    int i = 1;
    while (i <= 65536) {
        two[i] = 1; i *= 2;
    }
    int t = 5;
    while (t--) {
        int n, a, b; cin >> n;
        a = n; b = n;
        while (1) {
            if (two[a]) {
                cout << a << '\n'; break;
            }
            if (two[b]) {
                cout << b << '\n'; break;
            }
            a++; b--;
        }
    }
}