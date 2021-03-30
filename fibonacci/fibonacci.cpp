#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int mod = 1000000007;
ull n, fib[3];
int main() {
    cin >> n;
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[2] = (fib[0] + fib[1]) % mod;
        fib[0] = fib[1];
        fib[1] = fib[2];
    }
    cout << fib[2];
}