#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T, N, K;
int main() {
    cin >> T;
    while(T--) {
        ll cnt = 0, total = 0;
        cin >> N >> K;
        for (ll i = 1, a; i <= N; i++) {
            cin >> a;
            total += a;
            if (total >= K) {
                total = 0; cnt++;
            }
        }
        cout << cnt << '\n';
    }
}