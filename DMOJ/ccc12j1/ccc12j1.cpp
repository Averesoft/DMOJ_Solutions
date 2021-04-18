#include <bits/stdc++.h>
using namespace std;
int a, b;
string solve() {
    int diff = b - a;
    if (diff <= 0) return "Congratulations, you are within the speed limit!";
    if (diff >= 1 && diff <= 20) return "You are speeding and your fine is $" + to_string(100) + '.';
    if (diff >= 21 && diff <= 30) return "You are speeding and your fine is $" + to_string(270) + '.';
    if (diff >= 31) return "You are speeding and your fine is $" + to_string(500) + '.';
}
int main() {
    cin >> a >> b;
    cout << solve();
}