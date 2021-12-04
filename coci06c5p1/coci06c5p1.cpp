#include <bits/stdc++.h>
using namespace std;
string s;
int cup = 1;
int main() {
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') {
            if (cup == 1) {
                cup = 2;
            } else if (cup == 2) {
                cup = 1;
            }
        } else if (s[i] == 'B') {
            if (cup == 2) {
                cup = 3;
            } else if (cup == 3) {
                cup = 2;
            }
        } else {
            if (cup == 1) {
                cup = 3;
            } else if (cup == 3) {
                cup = 1;
            }
        }
    }
    cout << cup;
}