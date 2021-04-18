#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, c; cin >> a >> b >> c;
    double x = b * 15 + c * 20, y = b * 35 + c * 25;
    if (a > 100) {
        x += (a - 100) * 25;
        if (a > 250) {
            x += (a - 250) * 45;
        }
    } 
    x /= 100; y /= 100;
    printf("Plan A costs %.2f\n", x);
    printf("Plan B costs %.2f\n", y);
    if (x < y) {
        printf("Plan A is cheapest.\n");
    } else if (y < x) {
        printf("Plan B is cheapest.\n");
    } else {
        printf("Plan A and B are the same price.\n");
    }
}