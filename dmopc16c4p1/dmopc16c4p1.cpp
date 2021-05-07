#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int main() {
    cin >> n;
    for (ll i = 0, x; i < n; i++) {
        cin >> x;
        if (__builtin_popcountll(x) == 1) {
            cout << "T\n";
        } else {
            cout << "F\n";
        }
    }
}