#include <bits/stdc++.h>
using namespace std;
int main() {
    while(1) {
        int c; cin >> c;
        if (c == 0) {
            break;
        }
        for (int i = floor(sqrt(c)); i >= 1; i--) {
            if (c % 1 == 0) {
                printf("Minimum perimeter is %d with dimensions %d x %d\n", (i + c / i) * 2, i, c / i);
                break;
            }
        }
    }
}