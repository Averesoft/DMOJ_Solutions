#include <bits/stdc++.h>
using namespace std;
const int mm = 10 + 5;
int N;
double E[mm];
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> E[i];
    }
    bool a = 1, g = 1;
    for (int i = 2; i <= N - 1; i++) {
        if (2 * E[i] != E[i - 1] + E[i + 1]) {
            a = 0;
        }
        if (E[i] * E[i] != E[i - 1] * E[i + 1]) {
            g = 0;
        }
    }
    if (a && g) {
        cout << "both";
    } else if (a) {
        cout << "arithmetic";
    } else if (g) {
        cout << "geometric";
    } else {
        cout << "random";
    }
}