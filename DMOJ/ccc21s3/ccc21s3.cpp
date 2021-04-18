#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
struct friends{ ll p, w, d;};
ll n;
vector<ll> endpoints;
vector<friends> vc;
ll cost(ll idx) {
    ll sum = 0;
    for (friends u : vc) {
        if (idx < u.p-u.d || idx > u.p + u.d) {
            sum += abs(abs(idx-u.p)-u.d)*u.w;
        }
    }
    return sum;
}
int main() {
    cin >> n;
    for (ll i = 0, p, w, d; i < n; i++) {
        cin >> p >> w >> d;
        endpoints.push_back(p+d);
        endpoints.push_back(p-d);
        vc.push_back({p, w, d});
    }
    sort(endpoints.begin(), endpoints.end());
    ll lo = 0, hi = endpoints.size()-1, mid = (lo+hi)/2;
    while(lo < hi) {
        mid = (lo+hi)/2;
        if (cost(endpoints[mid]) < cost(endpoints[mid]+1)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    mid = (lo+hi)/2;
    cout << cost(endpoints[mid]);
}