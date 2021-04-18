#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        int a; string b; cin >> b >> a;
        if (b == "North") {
            y += a;
        } else if (b == "South") {
            y -= a;
        } else if (b == "West") {
            x -= a;
        } else if (b == "East") {
            x += a;
        }
    }
    cout << x << ' ' << y;
}