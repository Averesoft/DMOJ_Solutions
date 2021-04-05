#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; getline(cin, s);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string name, temp = ""; cin >> name;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '>') {
                temp += name;
            } else {
                temp += s[j];
            }
        }
        cout << temp << '\n';
    }
}