#include <bits/stdc++.h>
using namespace std;
int n, k, cnt = 0, num = 0;
int main() {
    cin >> n;
    cin >> k;
    while (n > 0) {
        n--; cnt++; num++;
        if (cnt == k) {
            n++; cnt = 0;
        }
    }
    cout << num;
}