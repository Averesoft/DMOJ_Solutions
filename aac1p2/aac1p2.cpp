#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mm = 1e6 + 5;
ll n, d, k, x, a[mm], p;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> d >> k >> x;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> p;
    vector<int> vc;
    for (ll i = 0; i < n; i++) {
        while(a[i] >= p) {
            a[i] = (double) a[i] * (100.0 - x)/100.0;
            k--;
        }
        if (k < 0) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}