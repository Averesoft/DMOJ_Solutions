#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mm = 5000 + 5;
ll N, M, K, Q, grid[mm][mm];
int main() {
    cin >> N >> M >> K;
    for (ll i = 1, x, y, X, Y; i <= K; i++) {
        cin >> x >> y >> X >> Y;
        grid[x][y]++; 
        grid[x][Y + 1]--; 
        grid[X + 1][y]--; 
        grid[X + 1][Y + 1]++;
    }
    for (ll i = 1; i <= mm - 1; i++) {
        for (ll j = 1; j <= mm - 1; j++) {
            grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
        }
    }
    for (ll i = 1; i <= mm - 1; i++) {
        for (ll j = 1; j <= mm - 1; j++) {
            grid[j][i] += grid[j - 1][i] + grid[j][i - 1] - grid[j - 1][i - 1];
        }
    }
    cin >> Q;
    for (ll i = 1, A, B, C, D; i <= Q; i++) {
        cin >> A >> B >> C >> D;
        cout << grid[C][D] - grid[A - 1][D] - grid[C][B - 1] + grid[A - 1][B - 1] << '\n';
    }
}