#include <bits/stdc++.h>
using namespace std;
const int mm = 500 + 5;
int n, ans = 0;
bool graph[mm][mm];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char ch; cin >> ch;
            if (ch == '1') {
                graph[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                graph[j][k] |= graph[i][k] && graph[j][i];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (!graph[i][j] && !graph[j][i]) {
                ans++;
            }
        }
    }
    cout << ans << '\n';
}