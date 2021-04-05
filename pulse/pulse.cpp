#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, s, t, cnt = 0;
int main() {
    cin >> n >> s >> t;
    for (ll i = 0, a; i < n; i++) {
        cin >> a; 
        if (a * 2 >= s && a * 2 <= t) cnt++;
    }
    cout << cnt;
}