#include <bits/stdc++.h>
using namespace std;
struct cow {int w, x, d;};
int N, L, sum, stop, t, ans = 0; vector<cow> a; deque<int> lft, rit, w;
int main() {
    cin >> N >> L; a.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i].w >> a[i].x >> a[i].d;
    }
    sort(a.begin(), a.end(), [](cow a, cow b) {return a.w < b.w;});
    for (cow x : a) {
        w.push_back(x.w);
        x.d < 0 ? lft.push_back(x.x) : rit.push_back(x.x);
    }
    while(stop * 2 < sum) {
        int tl = 1e9, tr = 1e9;
        if (lft.size()) tl = lft.front();
        if (rit.size()) tr = L - rit.back();
        if (tl < tr) {
            stop += w.front(); t = tl;
            if (rit.size()) {
                ans += upper_bound(rit.begin(), rit.end(), tl) - rit.begin();
            }
            w.pop_front(); lft.pop_front();
        } else {
            stop += w.back(); t = tr;
            if (lft.size()) {
                ans += (int)lft.size() - upper_bound(lft.begin(), lft.end(), tr);
            }
            w.pop_back(); rit.pop_back();
        }
    }
    for (int x : lft) {
        ans += upper_bound(rit.begin(), rit.end(), x) - lower_bound(rit.begin(), rit.end(), x - 2 * t);
    }
    cout << ans;
}