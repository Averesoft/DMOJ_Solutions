#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, k;
unordered_map<ll, int> row, col;
vector<int> vr, vc;
int main() {
    cin >> n >> m >> k;
    for (ll i = 0, a, b; i < k; i++) {
        cin >> a >> b; row[a] ^= 1; col[b] ^= 1;
    }
    for (auto e : row) {
        if (e.second) vr.push_back(e.first);
    }
    for (auto e : col) {
        if (e.second) vc.push_back(e.first);
    }
    int ans = max(vr.size(), vc.size()), sz = min(vr.size(), vc.size());
    cout << ans << '\n';
    for (int i = 0; i < sz; i++) {
        cout << vr[i] << ' ' << vc[i] << '\n';
    }
    for (int i = sz; i < vr.size(); i++) {
        cout << vr[i] << ' ' << 1 << '\n';
    }
    for (int i = sz; i < vc.size(); i++) {
        cout << 1 << ' ' << vc[i] << '\n';
    }
}