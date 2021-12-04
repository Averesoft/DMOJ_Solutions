//greed island is kinda sick rn, really hyped for chimera ant arc
#include <bits/stdc++.h>
using namespace std;
const int mm = 1100 + 5;
int instruction, N, A, B, X, Y, bit[mm][mm];
void update(int a, int b, int val) {
    for (int i = a; i <= mm; i += i & -i) {
        for (int j = b; j <= mm; j += j & -j) {
            bit[i][j] += val;
        }
    }
}
int gon(int a, int b) {
    int ans = 0;
    for (int i = a; i > 0; i -= i & - i) {
        for (int j = b; j > 0; j -= j & -j) {
            ans += bit[i][j];
        }
    }
    return ans;
}
int killua(int a, int b, int c, int d) {
    return gon(c, d) + gon(a - 1, b - 1) - gon(a - 1, d) - gon(c, b - 1);
}
int main() {
    while(1) {
        cin >> instruction;
        if (instruction == 3) {
            break;
        } else if (instruction == 0) {
            cin >> N;
        } else if (instruction == 1) {
            cin >> A >> B >> X;
            update(A + 1, B + 1, X);
        } else if (instruction == 2) {
            cin >> A >> B >> X >> Y;
            cout << killua(A + 1, B + 1, X + 1, Y + 1) << '\n';
        }
    }
    
}