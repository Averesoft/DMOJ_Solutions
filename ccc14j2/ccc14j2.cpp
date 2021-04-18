#include <bits/stdc++.h>
using namespace std;
int v, a[2];
int main() {
    cin >> v;
    for (int i = 0; i < v; i++) {
        char ch; cin >> ch;
        a[ch - 'A']++;
    }
    if (a[0] > a[1]) {
        cout << "A";
    } else if (a[0] < a[1]) {
        cout << "B";
    } else {
        cout << "Tie";
    }
}