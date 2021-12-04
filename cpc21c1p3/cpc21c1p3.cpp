#include <bits/stdc++.h>
using namespace std;
int R1, R2, R3;
void solve() {
    double ans = 0;
    cin >> R1 >> R2 >> R3;
    if (R3 - R2 < -(R1 + R3)) {
        ans += (R3 - R2) * (R3 - R2) - (R1 + R3) * (R1 + R3);
    }
    if (R1 > R3) {
        ans += (R1 - R3) * (R1 - R3);
    } else if (R3 > R1) {
        ans += min(R2 - R3, R3 - R1) * min(R2 - R3, R3 - R1);
    }
    printf("%.3f\n", ans / ((R2 - R3) * (R2 - R3)));
}
int main() {
    int T; cin >> T;
    while(T--) {
        solve();
    }
}