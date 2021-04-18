#include <bits/stdc++.h>
using namespace std;
int main() {
    int x, cnt = 0; cin >> x;
    for (int i = 0; i <= 5; i++) {
        for (int j = i; j <= 5; j++) {
            if (i + j == x) {
                cnt++;
            }
        }
    }
    cout << cnt;
}