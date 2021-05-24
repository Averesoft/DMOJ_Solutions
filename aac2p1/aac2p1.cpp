#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, fre[26]; string s;
int main() {
    memset(fre, 0, sizeof (fre));
    cin >> n;
    cin >> s;
    for (ll i = 0; i < n; i++) {
        fre[s[i] - 'a']++;
    }
    ll ans = 0;
    for (ll i = 0; i < 26; i++) {
        if (fre[i] % 2 == 1) ans++;
    }
    if (ans == 0) ans++;
    cout << ans << '\n';
}