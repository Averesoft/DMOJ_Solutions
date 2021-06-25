#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mm = 26 + 5;
ll a[mm], b[mm];
int main() {
    string x, y; cin >> x >> y;
    if (y.size() > x.size()) {
        cout << "No"; return 0;
    }
    for (ll i = 0; i < x.size(); i++) {
        a[x[i] - 'a']++;
    }
    for (ll i = 0; i < y.size(); i++) {
        a[y[i] - 'a']--;
    }
    ll cnt = 0;
    for (ll i = 0; i < 26; i++) {
        cnt += (a[i] >= 0 ? a[i] : 0);
        if (cnt > 1) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}