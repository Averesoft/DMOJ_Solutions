#include <bits/stdc++.h>
using namespace std;
const int mm = 50 + 5;
int R, C, ZR, ZC;
char grid[mm][mm];
int main() {
    cin >> R >> C >> ZR >> ZC;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < R; i++) {
        for (int x = 0; x < ZR; x++) {
            for (int j = 0; j < C; j++) {
                for (int y = 0; y < ZC; y++) {
                    cout << grid[i][j];
                }
            }
            cout << '\n';
        }   
    }
}