#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mm = 1e3 + 5, mod = 1e9 + 7;
int n, a[mm], d;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    cin >> d;
    for (int i = 1, k; i <= d; i++) {
        cin >> k;
    }
}