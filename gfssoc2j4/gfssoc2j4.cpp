#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mm = 500000 + 5;
int n, q, k[mm];
int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        k[i] += k[i - 1];
    }
    for (int i = 1; i <= q; i++) {
        int a, b; cin >> a >> b;
        cout << k[n] - (k[b] - k[a - 1]) << '\n';
    }
}