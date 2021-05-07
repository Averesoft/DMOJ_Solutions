#include <bits/stdc++.h>
using namespace std;
bool con(char c) {
    return c != 'A';
}
bool vow(char c) {
    return c == 'A';
}
int main() {
    string s; cin >> s;
    string temp = ""; int i = 0;
    while (i < s.size()) {
        temp += s[i];
        if ((vow(s[i]) && vow(s[i + 1])) || (con(s[i]) && con(s[i + 1]))) {
            cout << temp << ' ';
            temp = "";
        }
        i++;
    }
    if (temp != "") {
        cout << temp;
    }
    cout << '\n';
}