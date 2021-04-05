#include <bits/stdc++.h>
using namespace std;
int n, a;
int main() {
    cin >> n >> a;
    for (int i = 1, x; i < n; i++) {
        cin >> x;
        if (x >= a) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}