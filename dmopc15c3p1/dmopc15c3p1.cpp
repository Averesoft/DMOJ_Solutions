#include <bits/stdc++.h>
using namespace std;
int araara[11];
int main() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    for (int i = a; i <= b; i++) {
        araara[i]++;
    } 
    for (int i = c; i <= d; i++) {
        araara[i]++;
    }
    int cnt = 0;
    for (int i = 1; i <= 10; i++) {
        if (araara[i] == 2) {
            cnt++;
        }
    }
    if (cnt > 1) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}