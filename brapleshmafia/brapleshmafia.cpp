#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, K, sum = 0;
int main() {
    cin >> N >> K;
    for (ll i = 0, a, b; i < N; i++) {
        cin >> a >> b;
        sum += a * b % K;
    }
    cout << sum % K;
}