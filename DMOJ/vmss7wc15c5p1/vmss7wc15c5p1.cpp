#include <bits/stdc++.h>
using namespace std;
int main() {
    string status; cin >> status;
    double a, b, c;
    int ma = -1;
    for (int i = 0; i < 4; i++) {
        cin >> a >> b >> c;
        ma = max(ma, (int) (a * c));
    }
    cout << 100 - ma;
}