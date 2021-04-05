#include <bits/stdc++.h>
using namespace std;
bool solve(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != 'I' && s[i] != 'O' && s[i] != 'S' && s[i] != 'H' && s[i] != 'Z' && s[i] != 'X' && s[i] != 'N') {
            return 0;
        }
    }
    return 1;
}
int main() {
    string s; cin >> s;
    cout << (solve(s) ? "YES" : "NO");    
}