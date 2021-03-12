#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mm = 1000 + 5;
int n;
int grid[mm][mm];
bool lol[mm][mm];
ll solve() {
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        vector<bool> possible(n, true);
        for (int j = i; j < n; j++) {
            int ok = 0;
            for (int k = 0; k < n; k++) {
                possible[k] = (possible[k] & lol[j][k]);
                if (possible[k]) {
                    sum += ++ok;
                } else {
                    ok = 0;
                }
            }
        }
    }
    return sum;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            lol[i][j] = (grid[i][j] >= 100);
        }
    }
    ll sum = solve();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            lol[i][j] = (grid[i][j] > 100);
        }
    }
    sum -= solve();
    cout << sum;
}