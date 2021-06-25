#include <bits/stdc++.h>
using namespace std;
typedef pair<int, string> pis;
const int mm = 100000 + 5;
int m, n;
vector<string> ans(mm);
vector<pis> vc;
int main() {
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        pis t; cin >> t.first >> t.second;
        vc.push_back(t);
    }
    sort(vc.begin(), vc.end());
    for (pis u : vc) {
        for (int i = u.first; i <= n; i += u.first) {
            ans[i] += u.second;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (ans[i] == "") {
            cout << i;
        } else {
            cout << ans[i];
        }
        cout << '\n';
    }
}