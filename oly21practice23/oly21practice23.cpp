#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string a, b;
int main() {
    cin >> a >> b;
    string ta = "", tb = "";
    for (ll i = b.size() - 1; i >= 0; i--) {
        tb += b[i];
    }
    for (ll i = a.size() - 1; i >= 0; i--) {
        ta += a[i];
    }
    if (ta > tb) {
        cout << stoll(tb);
    } else {
        cout << stoll(ta);
    }
}