#include <bits/stdc++.h>
using namespace std;
int h;
int main() {
    cin >> h;
    for (int i = 1; i <= h; i += 2) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        for (int j = 1; j <= h - i; j++) {
            cout << "  ";
        }
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << '\n';
    }
    for (int i = h - 2; i >= 1; i -= 2) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        for (int j = 1; j <= h - i; j++) {
            cout << "  ";
        }
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << '\n';
    }
}