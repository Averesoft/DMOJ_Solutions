#include <bits/stdc++.h>
using namespace std;
int n, a[20 + 5], sum = 0;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (a[0] <= 41 && a[1] <= 41) {
        sum++;
    }
    if (a[n - 1] <= 41 && a[n - 2] <= 41) {
        sum++;
    }
    for (int i = 1; i < n - 1; i++) {
        if (a[i - 1] <= 41 && a[i] <= 41 && a[i + 1] <= 41) {
            sum++;
        }
    }
    cout << sum;
}