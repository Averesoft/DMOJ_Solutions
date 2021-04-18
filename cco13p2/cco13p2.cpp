#include <bits/stdc++.h>
using namespace std;
const int mm = 20 + 1;
int n, m;
int a[(1<<mm)+5], seg[(1<<mm)+5];
void construct() {
    for (int i = 0; i < (1 << n); i++) {
        seg[i+(1<<n)] = i;
    }
    for (int i = (1 << n) - 1; i > 0; i--) {
        seg[i] = (a[seg[2 * i]] > a[seg[2 * i + 1]] ? seg[2 * i] : seg[2 * i + 1]);
    }
}
void update(int b, int v) {
    a[b] = v;
    b += (1 << n);
    for (int i = b / 2; i > 0; i/=2) {
        seg[i] = (a[seg[2 * i]] > a[seg[2 * i + 1]] ? seg[2 * i] : seg[2 * i + 1]);
    }
} 
int range(int b) {
    int wins = 0;
    for (int i = (b + (1 << n))/2; i > 0; i/=2) {
        if (seg[i] == b) {
            wins++;
        }
    }
    return wins;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < (1 << n); i++) {
        cin >> a[i];
    }
    construct();
    for (int i = 0; i < m; i++) {
        char ch; cin >> ch;
        if (ch == 'R') {
            int pos, ski; cin >> pos >> ski; pos--;
            update(pos, ski);
        } else if (ch == 'W') {
            cout << seg[1]+1 << '\n';
        } else if (ch == 'S') {
            int pos; cin >> pos; pos--;
            cout << range(pos) << '\n';
        }
    }
}