#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    cin >> n;
    int ma = -1, sum = 0;;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a % 2 == 0) {
            sum += a;
        } else {
            ma = max(ma, sum);
            sum = 0;
        }
    }
    ma = max(ma, sum);
    cout << ma;
}