#include <bits/stdc++.h>
using namespace std;
int N;
int main() {
    cin >> N;
    int mix = INT_MAX, miy = INT_MAX, mx = INT_MIN, my = INT_MIN;
    for (int i = 0, x, y; i < N; i++) {
        cin >> x >> y;
        mix = min(mix, x);
        miy = min(miy, y);
        mx = max(mx, x);
        my = max(my, y);
    }
    cout << (my - miy) * (mx - mix);
}