#include <bits/stdc++.h>
using namespace std;
const int mm = 500 + 5, mmm = 100000 + 5;
int N, c[mm], sum = 0, f[mm][mmm];
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> c[i]; sum += c[i];
    }
    for (int i = 0; i <= sum; i++) {
        f[N + 1][i] = i;
    }
    int ma = -1;
    for (int i = N; i >= 1; i--) {
        for (int j = 0; j <= sum; j++) {
            if (j + c[i] <= sum) {
                f[i][j] = max(f[i + 1][j], max(f[i + 1][j + c[i]], f[i + 1][abs(j - c[i])]));
            } 
        }
    }
    for (int i = 0; i <= sum; i++) {
        ma = max(ma, f[N + 1][i]);
    }
    cout << ma;
    
}