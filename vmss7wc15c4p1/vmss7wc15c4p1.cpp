#include <bits/stdc++.h>
using namespace std;
int r, ans = 0; 
int main() {
    cin >> r;
    for (int i = -r; i <= r; i++) {
        double temp = sqrt(r * r - i * i);
        ans += (floor(temp) - ceil(-temp) + 1);
    }
    cout << ans;
}