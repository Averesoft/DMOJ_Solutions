#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, ans, lst; vector<pii> a;
int main() {
    cin >> n;
    for (int i = 0, st, ed; i < n; i++) {
        cin >> st >> ed; a.push_back({ed, st});
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (lst <= a[i].second) {
            ans++; lst = a[i].first;
        }
    }
    cout << ans << '\n';
}