#include <bits/stdc++.h>
using namespace std;
const int mm = 20 + 5;
int n, m;
int a[mm], idx[mm], seg[mm*2];
void construct() {
    for (int i = 1; i <= pow(2, n); i++) {
        seg[i+(int)pow(2, n)] = a[i];
    }
    for (int i = pow(2, n) - 1; i >= 0; i--) {
        seg[i] = idx[max(seg[i*2], seg[i*2+1])];
    }
}
void update(int x, int v) {
    int temp = x;
    x = x + pow(2, n);
    seg[x] = v;
    while (x > 1) {
        x /= 2;
        seg[x] = idx[max(seg[x*2], seg[x*2+1])];    
    }
    a[x] = v;
    idx[a[x]] = x;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= pow(2, n); i++) {
        cin >> a[i];
        idx[a[i]] = i;
    }
    construct();
    for (int i = 1; i <= m; i++) {
        char ch; cin >> ch;
        if (ch == 'R') {
            int pos, ski; cin >> pos >> ski;
            update(pos, ski);
        } else if (ch == 'W') {
            
        } else if (ch == 'S') {
            int pos; cin >> pos;
        }
    }
}