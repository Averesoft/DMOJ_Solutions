#include <bits/stdc++.h>
using namespace std;
const int mm = 1000 + 5;
int N, T, pumpkin[mm];
vector<int> l, r;
int main() {
    cin >> N >> T;
    for (int i = 0; i < N; i++) {
        cin >> pumpkin[i];
        if (pumpkin[i] > 0) {
            r.push_back(abs(pumpkin[i]));
        } else {
            l.push_back(abs(pumpkin[i]));
        }
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
}