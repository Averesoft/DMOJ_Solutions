#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii; 
const int mm = 1000 + 5;
int N, M;
char grid[mm][mm];
int main() {
    memset(grid, '.', sizeof (grid));
    cin >> N >> M;
    /*
    for (int i = 0; i <= N + 1; i++) {
        for (int j = 0; j <= M; j++) {
            grid[i][j] == '.';
        }
    }
    */
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> grid[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (grid[i][j] == 'G' && ((grid[i][j - 1] == 'C' && grid[i][j + 1] == 'C') || (grid[i - 1][j] == 'C' && grid[i + 1][j] == 'C'))) {
                grid[i][j] == '.'; 
                ans++;
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (grid[i][j] == 'C') {
                if (grid[i + 1][j - 1] == 'C') {
                    if (grid[i][j - 1] == 'G') {
                        grid[i][j - 1] = '.'; 
                        ans++;
                    } else if (grid[i + 1][j] == 'G') {
                        grid[i + 1][j] = '.'; 
                        ans++;
                    }
                }
                if (grid[i + 1][j + 1] == 'C') {
                    if (grid[i][j + 1] == 'G') {
                        grid[i][j + 1] = '.'; 
                        ans++;
                    } else if (grid[i + 1][j] == 'G') {
                        grid[i + 1][j] = '.'; 
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans;
}