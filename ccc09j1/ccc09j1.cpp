#include <bits/stdc++.h>
using namespace std;
int main() {
    int sum = 91;
    int a, b, c; cin >> a >> b >> c;
    sum += a + b * 3 + c;
    cout << "The 1-3-sum is " << sum;
}