#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; cin >> s;
    int a = s[0] - '0';
    int b = s[1] - '0';
    int c = s[2] - '0';
    int d = s[4] - '0';
    int e = s[5] - '0';
    int f = s[6] - '0';
    int g = s[8] - '0';
    int h = s[9] - '0';
    int i = s[10] - '0';
    int j = s[11] - '0';
    if (a + b + c == d + e + f && d + e + f == g + h + i + j) {
        cout << "Goony!";
    } else {
        cout << "Pick up the phone!";
    }
}