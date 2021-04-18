#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
    cin >> n >> m;
    for (int i = 0, a, b, c, f; i < m; i++) {
        cin >> a >> b >> c >> f;
    }
    int flow, cost;
    cout << (int) (((double) flow / (double) cost) * (1000000));
}