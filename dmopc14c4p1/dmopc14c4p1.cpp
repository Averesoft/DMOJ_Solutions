#include <bits/stdc++.h>
using namespace std;
int main() {
    string s, ans = "", key = " 0123456789ABCDEFGHIJKLMNOPQ", out = "9ABCDEFGHIJKLMNOPQRSTUVWXYZ"; cin >> s;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < key.size(); j++) {
            if (s[i] == key[j]) {
                ans += out[j - 1];
            }
        }
    }
    cout << ans;
}