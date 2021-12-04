#include <bits/stdc++.h>
using namespace std;
const int mm = 1e6 + 5;
int N, P[mm], fre[100 + 5];
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> P[i]; fre[P[i]]++;
    }
    int mi = INT_MAX, mix, ma = -1, man;
    for (int i = 1; i <= 100; i++) {
        if (fre[i] < mi) {
            mi = fre[i];
            mix = i;
        }
        if (fre[i] > ma) {
            ma = fre[i];
            man = i;
        }
    }
    cout << man - mix;
}