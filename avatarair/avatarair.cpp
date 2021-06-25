#include <bits/stdc++.h>
using namespace std;
const int mm = 100 + 5;
int N, M;
int grid[mm][mm];
int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            char ch; cin >> ch;
            if (ch == '/') {
                grid[i][j] = 1;
            } else if (ch == '\\') {
                grid[i][j] = 2;
            }
        }
    }
}