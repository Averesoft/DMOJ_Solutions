#include <bits/stdc++.h>
using namespace std;
int A, B, cnt = 0;
int main() {
    cin >> A >> B;
    for (double i = A; i <= B; i++) {
        if (sqrt(i) == floor(sqrt(i))) {
            cnt++;
        }
    }
    cout << cnt;
}