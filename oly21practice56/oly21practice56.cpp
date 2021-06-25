#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x, y;
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main() {
    cin >> x >> y;
    cout << (x / gcd(x, y)) * y;
}