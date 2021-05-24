#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    cin >> n;
    string s = ""; double ma = -1;
    for (int i = 0; i < n; i++) {
        string st; double x; cin >> st >> x;
        if (x > ma) {
            ma = x; s = st;
        }
    }
    cout << s;
}