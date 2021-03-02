#include <bits/stdc++.h>
using namespace std;
const int mm = 1e4+5;
int n;
bool grid[mm][mm];
int solve(int a, int b, int c, int d, int e) {
    int sum = 0;
    for (int i = a; i <= c; i++) {
        for (int j = b; j <= d; j++) {
            if (grid[i][j] == e) {
                sum++;
            }
        }
    }
    return sum;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) {
            grid[i][j] = s[j] == 'L';
        }
    }
    for (int i = 1; i < n; i++) {
        grid[i][0] ^= grid[0][0];
        for (int j = 1; j < n; j++) {
            grid[i][j] = grid[i][j]^grid[0][j]^grid[i][0];
        }
    }
    if (solve(1, 1, n-1, n-1, false) == 0) {
        cout << "1 1\n";
        return 0;
    }
    if (solve(1, 1, n-1, n-1, true) == n-1) {
        for (int j = 1; j < n; j++) {
            if (solve(1, j, n-1, j, true) == n-1) {
                cout << "1 " << j+1 << '\n'; 
                return 0;
            } 
        }
        for (int i = 1; i < n; i++) {
            if (solve(i, 1, i, n-1, true) == n-1) {
                cout << i+1 << " 1\n";
                return 0;
            }
        }
        cout << "-1\n";
        return 0;
    }
    if (solve(1, 1, n-1, n-1, 1) != true) {
        cout << "-1\n";
        return 0;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (grid[i][j] == true) {
                cout << i+1 << ' ' << j+1 << '\n';
            }
        }
    }
} 