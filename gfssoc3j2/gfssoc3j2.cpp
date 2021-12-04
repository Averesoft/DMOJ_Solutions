#include <bits/stdc++.h>
using namespace std;
int N;
double C, num = 0;
int main() {
    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        double x; cin >> x;
        num += x;
    }
    if (C - num < 0.00) {
        cout << "Fardin's broke";
    } else {
        printf("%.2f", C - num);
    }
}
