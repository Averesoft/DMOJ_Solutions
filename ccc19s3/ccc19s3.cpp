#include <bits/stdc++.h>
using namespace std;
string in[3][3];
int square[3][3];
int main() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> in[i][j];
            if (in[i][j] == "X") {
                square[i][j] = -1000000000 - 1;
            } else {
                square[i][j] = stoi(in[i][j]);
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j <  3; j++) {
            cout << square[i][j] << ' ';
        }
        cout << '\n';
    }
}