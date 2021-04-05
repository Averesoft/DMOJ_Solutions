#include <bits/stdc++.h>
using namespace std;
int b[] = {100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 500000, 1000000};
int main() {
    int n, total = 0; cin >> n;
    for (int i = 0; i < 10; i++) {
        total += b[i];
    }
    for (int i = 0, a; i < n; i++) {
        cin >> a; total -= b[a - 1];
    }
    int temp; cin >> temp;
    cout << (temp > total / (10 - n) ? "deal" : "no deal");
}