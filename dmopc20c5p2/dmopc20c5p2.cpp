#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const ll mm = 1e6 + 5;
ll n, m, k = 0;
vector<pii> vc;
bool intersections(double i, double j, double x, double y) {
    return i == floor(i) && j == floor(j) && x == floor(x) && y == floor(y);
}
bool cmp(pii a, pii b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}
int main() {
    cin >> n >> m;
    double slope = (double) (n - 1.0) / (m - 1.0), b = 1 - slope;
    for (ll i = 1; i <= m; i++) {
        for (ll j = 1; j <= n; j++) {
            double x = (i) * slope + b, y = (j - b) / slope;
            if (((x >= j - 1 && x <= j) || (y >= i - 1 && y <= i)) && !intersections(i, j, x, y)) {
                k++; vc.push_back({j, i});
            }
        } 
    }
    sort(vc.begin(), vc.end(), cmp);
    cout << k << '\n';
    for (pii a : vc) {
        cout << a.first << ' ' << a.second << '\n';
    }
}