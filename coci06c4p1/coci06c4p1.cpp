#include <bits/stdc++.h>
using namespace std;
int N, W, H;
int main() {
    cin >> N >> W >> H;
    double l = sqrt(W * W + H * H);
    for (int i = 0, a; i < N; i++) {
        cin >> a;
        if (a <= l) {
            cout << "DA";
        } else {
            cout << "NE";
        }
        cout << '\n';
    }
}