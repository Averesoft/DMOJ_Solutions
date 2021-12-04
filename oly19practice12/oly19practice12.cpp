#include <bits/stdc++.h>
using namespace std;
const int mm = 2 * 1e4 + 5;
int N, K, psa[mm], dp[2][mm], mx[2][mm];
int main() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> psa[i]; psa[i] += psa[i - 1];
    }
}