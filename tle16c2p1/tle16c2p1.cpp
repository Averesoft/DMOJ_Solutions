#include <bits/stdc++.h>
using namespace std;
int N, sum = 0, mi = INT_MAX, idx = -1;
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        string c; int x; cin >> c >> x;
        if (c == "borrow") {
            sum -= x;
        } else {
            sum += x;
        }
        if (sum < mi) {
            mi = sum;
            idx = i;
        }
    }
    cout << idx;
}