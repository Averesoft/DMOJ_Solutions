#include <bits/stdc++.h>
using namespace std;
const int mm = 1e5 + 5;
int n, q, d[mm], seg[2*mm];
void construct() {
    for (int i = 0; i < n; i++) {
        seg[i+n] = d[i];
    }
    for (int i = n-1; i > 0; i--) {
        
    }
}
void update(int x, int v) {
    d[x] = v;
    x += n;
    seg[x] = v;
    while(x > 1) {
        x /= 2;
        
    }
}
int range(int l, int r) {

}
int main() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    for (int i = 0; i < q; i++) {
        char ch; cin >> ch; 
        if (ch == 'S') {
            int i, x; cin >> i >> x;
            update(i, x);
        } else if (ch == 'Q') {
            int l, r; cin >> l >> r;
            cout << range(l, r) << '\n';
        }
    }
}