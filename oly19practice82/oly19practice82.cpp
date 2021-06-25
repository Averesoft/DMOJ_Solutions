#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mm = 1e6 + 5;
ll n, m;
unordered_map<vector<bool>, bool> mp;
unordered_map<vector<bool>, vector<bool>> pre;
int main() {
    cin >> n >> m;
    vector<bool> a(n + 1), tp;
    for (ll i = 1, x; i <= n; i++) {
        cin >> x; a[i] = x;
    }
    mp[a] = 1; pre[a] = tp;
    while(m--) {
        vector<bool> temp;
        bool f = a[1];
        for (ll i = 1; i <= n - 1; i++) {
            temp.push_back(a[i]);
            if (a[i + 1]) {
                a[i] = !a[i];
            }
        }
        if (f) {
            temp.push_back(a[n]);
            a[n] = !a[n];
        }
        if (mp[a]) {
            vector<vector<bool>> vcc;
            for (auto i = pre[a]; i != tp; i = pre[i]) {
                vcc.push_back(i);
            }
            reverse(vcc.begin(), vcc.end());
            vector<bool> tpp = vcc[m % vcc.size()];
            for (int i = 1; i <= n; i++) {
                cout << tpp[i] << '\n';
            }
            return 0;
        }
    }
    for (ll i = 1; i <= n; i++) {
        cout << a[i] << '\n';
    }
}