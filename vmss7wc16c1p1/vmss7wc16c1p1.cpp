#include <bits/stdc++.h>
using namespace std;
int Y;
int main() {
    cin >> Y;
    while(Y % 2 == 0) {
        cout << 2 << '\n';
        Y /= 2;
    }
    for (int i = 3; i <= sqrt(Y); i += 2) {
        while (Y % i == 0) {
            cout << i << '\n';
            Y /= i;
        }
    }
    if (Y > 2) {
        cout << Y;
    }
}