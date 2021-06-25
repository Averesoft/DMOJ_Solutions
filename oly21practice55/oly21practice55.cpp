#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
string s, ans = "";
unordered_set<string> sub;
int main() {
    cin >> s;
    for (ll i = 0; i < s.size(); i++) {
        for (ll j = 0; j < s.size(); j++) {
            sub.insert(s.substr(i, j + 1));
        }
    }
    ll sze = 0;
    for (ll i = 0; i < s.size(); i++) {
        sze = sub.size();
        for (ll j = 'a'; j <= 'z'; j++) {
            sub.insert(ans + (char) j);
            if (sub.size() > sze) {
                cout << ans + (char) j; return 0;
            }
        }
        ans += 'a';
    }
    cout << ans + 'a';
}