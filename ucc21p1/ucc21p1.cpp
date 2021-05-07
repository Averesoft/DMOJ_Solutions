#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; cin >> s;
    int ans = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == '2' && s[i + 1] != '5') {
            ans++;
        }
    }
    if (s[s.size() - 1] == '2') ans++;
    cout << ans;
}