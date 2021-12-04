#include <bits/stdc++.h>
using namespace std;
const int mm = 1000 + 5;
int N, K, psa[mm][mm];
int main() {
    cin >> N >> K;
    for (int i = 1, x1, y1, x2, y2; i <= N; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        x1++; y1++; x2++; y2++;
        psa[x1][y1]++; psa[x2][y2]++; psa[x1][y2]--; psa[x2][y1]--;
    }
    int cnt = 0;
    for (int i = 1; i < mm; i++) {
        for (int j = 1; j < mm; j++) {
            psa[i][j] += psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1];
            if (psa[i][j] == K) {
                cnt++;
            }
        }
    }
    cout << cnt;
}