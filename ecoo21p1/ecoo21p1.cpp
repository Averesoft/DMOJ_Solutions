#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, c; cin >> a >> b >> c;
    if (a + b >= c) {
        cout << a + b;
    } else if (a + b * 2 >= c) {
        cout << a + b * 2;
    } else if (a + b * 3 >= c) {
        cout << a + b * 3;
    } else {
        cout << "Who knows...";
    }
}