#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b; cin >> hex >> a >> hex >> b;
    if (a + b <= 0x3f3f3f3f) {
        cout << "No";
    } else {
        cout << "Yes";
    }
}