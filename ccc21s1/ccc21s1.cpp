#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mm = 10000 + 5;
ll n;
double h[mm], w[mm]; 
double ans = 0.0;
int main()
{
    cin >> n;
    for (ll i = 1; i <= n + 1; i++) {
        cin >> h[i];
    }
    for (ll i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for (ll i = 1; i <= n; i++) {
        ans += (h[i] + h[i + 1]) * w[i] / 2.0;
    }
    cout << fixed << setprecision(3) << ans ;
}