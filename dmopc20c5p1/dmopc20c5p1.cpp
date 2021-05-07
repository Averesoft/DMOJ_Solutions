#include <bits/stdc++.h>
using namespace std;
string s, t;
int main() {
    cin >> s >> t;
    int num = s.size();
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != t[i]) {
            num = i;
            break;
        }
    }
    cout << (s.size() - num) + (t.size() - num) << '\n';
}