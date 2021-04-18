#include <bits/stdc++.h>
using namespace std;
string solve(int a, int b, int c, int d) {
    if (a == b && b == c && c == d) return "Fish At Constant Depth";
    if (a < b && b < c && c < d) return "Fish Rising";
    if (a > b && b > c && c > d) return "Fish Diving";
    return "No Fish";
}
int main() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    cout << solve(a, b, c, d);
}