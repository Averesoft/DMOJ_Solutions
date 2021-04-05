#include <bits/stdc++.h>
using namespace std;
string solve(int a, int b, int c) {
    if (a + b + c != 180) return "Error";
    if (a == 60 && b == 60 && c == 60) return "Equilateral";
    if (a == b || b == c || a == c) return "Isosceles";
    if (a != b && b != c && a != c) return "Scalene";
    return "";
}
int main() {
    int a, b, c; cin >> a >> b >> c;
    cout << solve(a, b, c);
}