#include <bits/stdc++.h>
using namespace std;
const int mm = 1000 + 5;
int r, c; 
bool row[mm], col[mm];
int main() {
    cin >> r >> c;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            char ch; cin >>ch;
            if (ch == 'X') {
                row[i] = 1; col[j] = 1;
            }
        }
    }
    int q; cin >> q;
    for (int i = 0, x, y; i < q; i++) {
        cin >> x >> y;
        cout << (row[y] || col[x] ? "Y" : "N") << '\n';
    }
}