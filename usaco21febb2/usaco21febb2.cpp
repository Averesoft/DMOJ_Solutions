#include <bits/stdc++.h>
using namespace std;
const int mm = 1e4 + 5;
int n;
bool cow[mm][mm];
bool cmp(int x, int y){ 
    return (x >= 0 && x <= n && y >= 0 && y <= n);
}
bool calc(int x, int y) {
    if (cow[x][y] == 0) {
        return false;
    }
    int adj = 0;
    if (cmp(x + 1, y)) {
        if (cow[x + 1][y]) {
            adj++;
        }
    }
    if (cmp(x - 1, y)) {
        if (cow[x - 1][y]) {
            adj++;
        }
    }
    if (cmp(x, y + 1)) {
        if (cow[x][y + 1]) {
            adj++;
        }
    }
    if (cmp(x, y - 1)) {
        if (cow[x][y - 1]) {
            adj++;
        }
    }
    return adj == 3;
}
int main() {
    cin >> n;
    int comfortable = 0;
    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y;
        if (cmp(x + 1, y)) {
            comfortable -= calc(x + 1, y);
        }
        if (cmp(x - 1, y)) {
            comfortable -= calc(x - 1, y);
        }
        if (cmp(x, y + 1)) {
            comfortable -= calc(x, y + 1);
        }
        if (cmp(x, y - 1)) {
            comfortable -= calc(x, y - 1);
        }
        cow[x][y] = true;
        if (cmp(x + 1, y)) {
            comfortable += calc(x + 1, y);
        }
        if (cmp(x - 1, y)) {
            comfortable += calc(x - 1, y);
        }
        if (cmp(x, y + 1)) {
            comfortable += calc(x, y + 1);
        }
        if (cmp(x, y - 1)) {
            comfortable += calc(x, y - 1);
        }
        comfortable += calc(x, y);
        cout << comfortable << '\n';
    }
}