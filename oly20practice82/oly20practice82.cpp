#include <bits/stdc++.h>
using namespace std;
const int mm = 1e5 + 5;
int n, q, a[mm];
vector<int> vc;
int main() {
    cin >> n >> q;
    for (int i = 0, p; i < n; i++) {
        cin >> p; vc.push_back(p);
    }
    sort(vc.begin(), vc.end());
    for (int i = 0, l, r; i < q; i++) {
        cin >> l >> r;
        int sum = 0;
        for (int p : vc) {
            if (p >= l && p <= r) {
                sum++;
            }
        }
        cout << sum << '\n';
    }
}