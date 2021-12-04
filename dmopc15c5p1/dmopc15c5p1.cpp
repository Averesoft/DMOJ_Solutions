#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
    return (b == 0 ? a : gcd(b, a % b));
}
ll A, B, X, least;
int main() {
    cin >> A >> B >> X;
    least = A * B / gcd(A, B);
    cout << (X - 1) / least + 1;
}