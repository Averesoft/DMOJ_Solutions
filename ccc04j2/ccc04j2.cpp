#include <bits/stdc++.h>
using namespace std;
int main() {
    int x, y; cin >> x >> y;
    for (int i = x; i <= y; i++) {
        int j = i - x;
        if (j % 4 == 0 && j % 2 == 0 && j % 3 == 0 && j % 5 == 0) {
            printf("All positions change in year %d\n", i);
        }
    }
}