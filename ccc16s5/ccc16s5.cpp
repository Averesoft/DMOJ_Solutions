#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mm = 100000 + 5;
ll n, t, num = 1;
bool a[mm], b[mm];
int main() {
    cin >> n >> t;
    string st; cin >> st;
    for (ll i = 0; i < n; i++) {
        a[i] = st[i] == '1';
    }
    while (t > 0) {
        if (t & 1) {
            for (ll i = 0; i < n; i++) {
                b[i] = a[(i + num % n) % n] ^ a[(i - num % n + n) % n];
            }
            for (ll i = 0; i < n; i++) {
                a[i] = b[i];
            }
        }
        num <<= 1; t >>= 1; 
    }
    for (ll i = 0; i < n; i++) {
        cout << a[i];
    }
}