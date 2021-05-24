#include <bits/stdc++.h>
using namespace std;
int a, n;
int main() {
    cin >> a;
    cin >> n;
    for (int i = 0, k; i < n; i++) {
        cin >> k;
        if (abs(a - k) <= 100) {
            cout << "fite me! >:3\n";
        } else {
            cout << "go away! 3:<\n";
        }
    }
}