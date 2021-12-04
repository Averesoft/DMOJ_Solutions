#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, c, ac = 0, bc = 0;
    cin >> a >> b >> c;
    ac += a * 3 + b * 2 + c;
    cin >> a >> b >> c;
    bc += a * 3 + b * 2 + c;
    if (ac > bc) {
        cout << 'A';
    } else if (bc > ac) {
        cout << 'B';
    } else if (ac == bc) {
        cout << 'T';
    }
}