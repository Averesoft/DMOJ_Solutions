#include <bits/stdc++.h>
using namespace std;
int W, C;
int main() {
    cin >> W >> C;
    if (W == 3 && C >= 95) {
        cout << "C.C. is absolutely satisfied with her pizza.";
    } else if (W == 1 && C <= 50) {
        cout << "C.C. is fairly satisfied with her pizza.";
    } else {
        cout << "C.C. is very satisfied with her pizza.";
    }
}