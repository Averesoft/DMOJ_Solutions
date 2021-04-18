#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k;
int main() {
    cin >> n >> k;
    ll mi = min(n % k, k - n % k);
    if (n < k) mi = k - n;
    cout << mi;
}