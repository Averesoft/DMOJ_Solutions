#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    cin >> n;
    int cnt = 0;
    while(n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n *= 3; n++;
        }
        cnt++;
    }
    cout << cnt;
}