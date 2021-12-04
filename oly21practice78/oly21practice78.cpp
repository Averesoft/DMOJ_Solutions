#include <bits/stdc++.h>
using namespace std;
const int mm = 100 + 5;
int N, h[mm];
int main() {
    cin >> N;
    int minh = 101, maxh = -101;
    for (int i = 1; i <= N; i++) {
        cin >> h[i]; minh = min(minh, h[i]); maxh = max(maxh, h[i]);    
    }
    int ans = INT_MAX;
    for (int i = minh; i <= maxh; i++) {
        int cost = 0;
        for (int j = 1; j <= N; j++) {
            cost += (h[j] - i) * (h[j] - i);
        }
        ans = min(ans, cost);
    }
    cout << ans << '\n';
}