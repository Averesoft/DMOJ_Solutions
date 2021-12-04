#include <bits/stdc++.h>
using namespace std;
int N, K;
double sum = 0;
int main() {
    cin >> N >> K;
    for (int j = 0, i; j < K; j++) {
        cin >> i;
        if (i == 1) {
            sum += 0.5;
        } else if (i == 2) {
            sum += 1.0;
        } else if (i == 3) {
            sum += 5;
        }
    }
    if (sum < N) {
        cout << "Continue";
    } else {
        cout << "Return";
    }
}