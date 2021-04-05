#include <bits/stdc++.h>
using namespace std;
int main() {
    int d; cin >> d;
    for (int i = 1; i <= d; i++) {
        int t, sum = 0; cin >> t;
        for (int j = 0, wood; j < t; j++) {
            cin >> wood; sum += wood;
        }
        (sum != 0 ? printf("Day %d: %d\n", i, sum) : printf("Weekend\n"));
    }
}