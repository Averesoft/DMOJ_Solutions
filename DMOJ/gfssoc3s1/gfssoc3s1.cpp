#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (ll i = 1; i <= n; i <<= 1) {
        cout << 1;
    }
}