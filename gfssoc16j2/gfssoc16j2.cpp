#include <bits/stdc++.h>
using namespace std;
double sum = 0;
int main() {
    for (int i = 0, a; i < 6; i++) {
        cin >> a; sum += a;
    }
    sum /= 6;
    int a; cin >> a;
    sum += a;
    cin >> a;
    if (sum >= a) {
        cout << "yes";
    } else {
        cout << "no";
    }
}