#include <bits/stdc++.h>
using namespace std;
int x, y;
int xo, yo, xt, yt;
int main() {
    cin >> x >> y;
    cin >> xo >> yo >> xt >> yt;
    if (x >= xo && y >= yo && x <= xt && y <= yt) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}