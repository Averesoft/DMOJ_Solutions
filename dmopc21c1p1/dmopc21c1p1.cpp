//i love this manga
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mm = 2 * 1e5 + 5;
ll N, A[mm], duke = 0, alice = 0;
int main() {
    cin >> N;
    for (ll i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (ll i = 1; i <= N; i++) {
        if (A[i] & 1) { 
            alice += A[i] + 1;
        } else {
            duke += A[i];
        }
    }
    if (duke > alice) {
        cout << "Duke\n";
    } else {
        cout << "Alice\n";
    }
}