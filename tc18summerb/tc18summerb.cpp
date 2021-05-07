#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c, d, e;
int main() {
    cin >> c >> d >> e;
    ll cnt = 1;
    for (int i = 0; i < 30; i++) {
        if (((e >> i) & 1) == 1) {
            cnt *= (((c >> i) & 1) && !((d >> i) & 1) ? 2 : 0);
        } else {
            cnt *= (((c >> i) & 1) == ((d >> i) & 1) ? 1 : 0);
        }
    }
    cout << cnt;
}