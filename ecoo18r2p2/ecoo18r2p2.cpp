#include <bits/stdc++.h>
using namespace std;
typedef pair<int, double> pid;
const int mm = 1e6 + 5;
int N, idx[mm];
pid A[mm];
bool cmp(pid a, pid b) {
    return a.second > b.second;
}
int masksusremix(int d) {
    if (idx[d] == d) {
        return d;
    }
    return idx[d] = masksusremix(idx[d]);
}
int main() {
    int T = 10;
    while (T--) {
        cin >> N;
        int ma = -1; double ans = 0.0;
        for (int i = 1; i <= N; i++) {
            cin >> A[i].first >> A[i].second;
            ma = max(ma, A[i].first);
        }
        sort(A + 1, A + N + 1, cmp);
        for (int i = 0; i <= ma; i++ ){
            idx[i] = i;
        }
        for (int i = 1; i <= N; i++) {
            int temp = masksusremix(A[i].first);
            if (temp > 0) {
                idx[temp] = temp - 1; 
                ans += A[i].second;
            }
        }
        printf("%.4f\n", ans);
    }
}