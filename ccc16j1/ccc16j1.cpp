#include <bits/stdc++.h>
using namespace std;
int main() {
    int count = 0;
    for (int i = 0; i < 6; i++) {
        char ch; cin >> ch;
        if (ch == 'W') {
            count++;
        }
    }
    if (count >= 5) {
        cout << 1;
    } else if (count >= 3) {
        cout << 2;
    } else if (count >= 1) {
        cout << 3;
    } else {
        cout << -1;
    }
}