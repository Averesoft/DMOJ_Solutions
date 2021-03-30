#include <bits/stdc++.h>
using namespace std;
struct rect{ int x, y, w, h; };
const int mm = 2 * 1e5 + 5;
int n;
vector<rect> vc;
int main() {
    cin >> n;
    for (int i = 0, x, y, w, h; i < n; i++) {
        cin >> x >> y >> w >> h; vc.push_back({x, y, w, h});
    }
    int p, q; cin >> p >> q;
    for (int i = vc.size() - 1; i >= 0; i--) {
        rect u = vc[i];
        if (p <= u.x + u.w && p >= u.x && q <= u.y + u.h && q >= u.y) {
            cout << i + 1;
            return 0;
        }
    }
    cout << -1;
}