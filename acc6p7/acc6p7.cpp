#include <bits/stdc++.h>
using namespace std;
int n; 
int main() {
    cin >> n;
    string s; cin >> s;
    string ans = "";
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            ans += "0";
        } else {
            ans += "1";
        }
    }
    cout << ans << '\n';
}