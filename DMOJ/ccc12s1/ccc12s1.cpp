#include <bits/stdc++.h>
using namespace std;
int main() {
    int x, cnt = 0; cin >> x;
    for (int i = 1; i < x; i++) {
        for (int j = i + 1; j < x; j++) {
            for (int k = j + 1; k < x; k++) {
                cnt++;
            }
        }
    }
    cout << cnt;
}