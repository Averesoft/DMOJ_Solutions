#include <bits/stdc++.h>
using namespace std;
int grid[4][4];
int main() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> grid[i][j];
        }
    }
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        sum += grid[i][0];
    }
    for (int i = 1; i < 4; i++) {
        int temp = 0;
        for (int j = 0; j < 4; j++) {
            temp += grid[i][j];
        }
        if (sum != temp) {
            cout << "not magic\n"; return 0;
        }
    }
    for (int j = 0; j < 4; j++) {
        int temp = 0;
        for (int i = 0; i < 4; i++) {
            temp += grid[i][j];
        }
        if (sum != temp) {
            cout << "not magic\n"; return 0;
        }
    }
    cout << "magic\n";
}