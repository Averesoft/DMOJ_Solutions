#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
ll N;
vector<pii> vc;
int main() {
    cin >> N;
    double sum = 0;
    for (ll i = 0, x, y; i < N; i++) {
        cin >> x >> y; vc.push_back({x, y});
    }
    vc.push_back({vc[0].first, vc[0].second});
    for (ll i = 0; i < N; i++) {
        sum += vc[i].first * vc[i + 1].second - vc[i].second * vc[i + 1].first;
    }
    cout << abs(ceil(sum / 2));
}