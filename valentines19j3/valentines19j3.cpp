#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[4];
int main() {
    string s; cin >> s;
    for (ll i = s.size() - 1; i >= 0; i--) {
        if (s[i] == 'e') a[3]++;
        else if (s[i] == 'v') a[2] += a[3];
        else if (s[i] == 'o') a[1] += a[2];
        else if (s[i] == 'l') a[0] += a[1];
    }
    cout << a[0];
}