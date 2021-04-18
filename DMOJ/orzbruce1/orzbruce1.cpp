#include <bits/stdc++.h>
using namespace std;
int main() {
    double a, b, c; cin >> a >> b >> c; a/= 1000; b /= 1000; c /= 1000;
    printf("%.2f", ((a/40.0) + (b/60.0) + (c/70.0)) * 60);
}