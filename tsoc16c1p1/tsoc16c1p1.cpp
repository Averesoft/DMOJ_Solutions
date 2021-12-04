#include <bits/stdc++.h>
using namespace std;
int N;
int main() {
    cin >> N;
    for (int i = 0, L, A, B, F; i < N; i++) {
        cin >> L >> A >> B >> F;
        if (L - F >= A && L - F <= B) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}