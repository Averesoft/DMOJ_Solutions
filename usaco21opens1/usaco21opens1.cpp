#include <bits/stdc++.h>
using namespace std;
const int mm = 25 + 5, threenine = 3 * 3 * 3 * 3 * 3 * 3 * 3 * 3 * 3;
int n, three[10 + 5];
bool vis[mm][mm][threenine];
char grid[mm][mm][3];
set<int> st;
bool test(int b) {
    int arr[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr[i][j] = b % 3;
            b /= 3;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (arr[i][0] == 1 && arr[i][1] == 2 && arr[i][2] == 2) {
            return 1;
        }
        if (arr[i][0] == 2 && arr[i][1] == 2 && arr[i][2] == 1) {
            return 1;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (arr[0][i] == 1 && arr[1][i] == 2 && arr[2][i] == 2) {
            return 1;
        }
        if (arr[0][i] == 2 && arr[1][i] == 2 && arr[2][i] == 1) {
            return 1;
        }
    }
    if (arr[0][0] == 1 && arr[1][1] == 2 && arr[2][2] == 2) {
        return 1;
    }
    if (arr[0][0] == 2 && arr[1][1] == 2 && arr[2][2] == 1) {
        return 1;
    }
    if (arr[2][0] == 1 && arr[1][1] == 2 && arr[0][2] == 2) {
        return 1;
    }
    if (arr[2][0] == 2 && arr[1][1] == 2 && arr[0][2] == 1) {
        return 1;
    }
    return 0;
}
void dfs(int x, int y, int state) {
    if (vis[x][y][state]) {
        return;
    }
    vis[x][y][state] = 1;
    if (grid[x][y][0]=='M' || grid[x][y][0]=='O') {
        int idx = (grid[x][y][1]-'1') * 3 + (grid[x][y][2] - '1');
        int ch = (state / three[idx]) % 3;
        if (ch == 0) {
            int temp = grid[x][y][0] == 'M' ? 1 : 2;
            state = (state % three[idx]) + temp * three[idx] + (state - state % three[idx + 1]);
            if (!vis[x][y][state] && test(state)) { 
                st.insert(state); return; 
            }
            vis[x][y][state] = 1;
        }
    }
    if (grid[x - 1][y][0] != '#') {
        dfs(x - 1, y, state);
    }
    if (grid[x + 1][y][0] != '#') {
        dfs(x + 1, y, state);
    }
    if (grid[x][y - 1][0] != '#') {
        dfs(x, y - 1, state);
    }
    if (grid[x][y + 1][0] != '#') {
        dfs(x, y + 1, state);
    }
}
int main() {
    cin >> n;
    three[0] = 1;
    for (int i = 1; i <= 9; i++) {
        three[i] = three[i - 1] * 3;
    }
    int startx, starty;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j][0] >> grid[i][j][1] >> grid[i][j][2];
            if (grid[i][j][0] == 'B') { 
                startx = i; starty = j; 
            }
    }
    dfs(startx, starty, 0);
    cout << st.size();
}