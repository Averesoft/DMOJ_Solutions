#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mm = 500 + 5;
int n;
int grid[mm][mm];
int lol[mm][mm];
bool findMin(int a, int b, int c, int d) {
    bool maybe = false;
    for (int i = a; i <= c; i++) {
        for (int j = b; j <= d; j++) {
            if (lol[i][j] == 0) {
                return false;
            }
            if (lol[i][j] == 2) {
                maybe = true;
            }
        }
    }
    return maybe;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n ;j ++) {
            cin >> grid[i][j];
            if (grid[i][j] > 100) {
                lol[i][j] = 1;
            } else if (grid[i][j] < 100) {
                lol[i][j] = 0;
            } else {
                lol[i][j] = 2;
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < n; l++) {
                    if (grid[i][j] == 0 || grid[k][l] == 0) continue;
                    if (findMin(i, j, k, l)) {
                        sum++;
                    }
                }
            }
        }
    }
    cout << sum;
}