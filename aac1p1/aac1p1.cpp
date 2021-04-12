#include <bits/stdc++.h>
using namespace std;
double s, r;
int main() {
    cin >> s >> r;
    s = s * s;
    r = 3.14 * r * r;
    if (s > r) {
        cout << "SQUARE";
    } else {
        cout << "CIRCLE";
    }
}