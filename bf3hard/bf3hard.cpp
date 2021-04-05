#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
bool test() {
    ll up = sqrt(n);
    if (n == 1) {
        return 0;
    }
    if (n == 2 || n == 3) {
        return 1;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return 0;
    }
    for (ll i = 6; i < up + 1; i += 6) {
        if (n % (i - 1) == 0) {
            return 0;
        }
        if (n % (i + 1) == 0) {
            return 0;
        }
    }
    return 1;
}
int main() {
    cin >> n;
    while(!test()) {
        n++;
    }
    cout << n;
}