#include <bits/stdc++.h>
using namespace std;
bool chk(int y, int m, int d) {
    if (y > 1989) return 0;
    if (y == 1989 && m > 2) return 0;
    if (y == 1989 && m == 2 && d > 27) return 0;
    return 1;
}
int main() {
    int n; cin >> n;
    for (int i = 0, y, m, d; i < n; i++) {
        cin >> y >> m >> d;
        cout << (chk(y, m, d) ? "Yes\n" : "No\n");
    }
}