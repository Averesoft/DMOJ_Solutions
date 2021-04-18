#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int mm = (25 + 5) * 3;
int n;
bool vis[mm][mm], 
int mo[mm][mm];
queue<int> q;
int main() {
    cin >> n;
    pii start;
    for (int i = 0; i < n * 3; i++) {
        for (int j = 0; j < n; j++) {
            char a, b, c; cin >> a >> b >> c;
            if (a == 'B') {
                start = {i, j};
            } else if (a == 'O') {
                vis[i][j] = 0;
                mo[i][j] = 1;
            } else if (a == 'M') {
                vis[i][j] = 0;
                mo[i][j] = 2;
            } else if (a == '.') {
                vis[i][j] = 0;
            } else {
                vis[i][j] = 1;
            }
        }
    }
    
}