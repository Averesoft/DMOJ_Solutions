#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b; cin >> a >> b;
    if (a > 2) {
        cout << "After";
    } else if (a < 2) {
        cout << "Before";
    } else {
        if (b > 18) {
            cout << "After";
        } else if (b < 18) {
            cout << "Before";
        } else {
            cout << "Special";
        }
    }
}