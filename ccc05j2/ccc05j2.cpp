#include <bits/stdc++.h>
using namespace std;
int chk(int x) {
    int num = 0;
    for (int i = 1; i <= x; i++) {
        if (x % i == 0) {
            num++;
        }
    }
    return num;
}
int main() {
    int l, r, cnt = 0; cin >> l >> r;
    for (int i = l; i <= r; i++) {
        if (chk(i) == 4) cnt++;
    }
    printf("The number of RSA numbers between %d and %d is %d", l, r, cnt);
}