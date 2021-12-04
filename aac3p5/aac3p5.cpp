#include <bits/stdc++.h>
using namespace std;
const int mm = 2 * 1e3 + 5;
int N, M;
bool grid[mm][mm];
int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            char ch; cin >> ch;
            grid[i][j] = (ch == '#' ? 0 : 1);
        }
    }
    
}