#include <iostream>
using namespace std;
const int mm = 9;
int n = 9, grid[mm][mm];
bool chk(int r, int c, int i) {
    for (int x = 0; x < n; x++) {
        if (grid[r][x] == i) return 0;
    }
    for (int x = 0; x < n; x++) {
        if (grid[x][c] == i) return 0;
    }
    int sr = r - r % 3, sc = c - c % 3;
    for (int a = 0; a < 3; a++) {
        for (int b = 0; b < 3; b++) {
            if (grid[a + sr][b + sc] == i) return 0;    
        }
    }
    return 1;
}
bool sudoku(int r, int c) {
    if (r == n - 1 && c == n) return 1;
    if (c == n) {
        r++; c = 0;
    }
    if (grid[r][c] > 0) return sudoku(r, c + 1);
    for (int i = 1; i <= n; i++) {
        if (chk(r, c, i)) {
            grid[r][c] = i;
            if(sudoku(r, c + 1)) {
                return 1;
            }
        }
        grid[r][c] = 0;
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char ch; cin >> ch;
            if (ch == '.') {
                grid[i][j] = 0;
            } else {
                grid[i][j] = ch - '1' + 1;
            }
        }
    }
    sudoku(0, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}