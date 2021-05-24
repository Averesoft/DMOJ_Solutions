#include <bits/stdc++.h>
using namespace std;
int n, x1, x2;
int main() {
    cin >> n;
    int ma = -1;
    for (int i = 0; i < n; i++) {
        cin >> x1 >> x2;
        ma = max(ma, x2 - x1);
    }
    cout << ma;
}