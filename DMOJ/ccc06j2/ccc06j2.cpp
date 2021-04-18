#include <bits/stdc++.h>
using namespace std;
int m, n;
int main() {
    cin >> m >> n;
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (i + j == 10) {
                cnt++;
            }
        }
    }
    cout << "There " << (cnt != 1 ? "are ":"is ") << cnt << " way" << (cnt != 1 ? "s":"") <<" to get the sum 10.";
}