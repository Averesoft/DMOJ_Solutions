#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    cin >> n;
    int an = 100, da = 100;
    for (int i = 0, a, d; i < n; i++) {
        cin >> a >> d;
        if (a > d) {
            da -= a;
        } else if (a < d) {
            an -= d;
        }
    }
    cout << an << '\n' << da;
}