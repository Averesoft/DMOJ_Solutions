#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, s;
int main() {
    cin >> a >> b >> c >> d >> s;
    int x = s / (a + b), y = s / (c + d);
    int nikky = x * (a - b), byron = y * (c - d), nsteps = x * (a + b), bsteps = y * (c + d);
    x = s - nsteps, y = s - bsteps;
    nikky += x; byron += y;
    if (x > a) {
        nikky -= x - a;
    }
    if (y > c) {
        byron -= y - c;
    }
    if (nikky > byron) {
        cout << "Nikky";
    } else if (byron > nikky) {
        cout << "Byron";
    } else {
        cout << "Tied";
    }
}