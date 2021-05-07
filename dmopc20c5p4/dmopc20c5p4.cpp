#include <bits/stdc++.h>
using namespace std;
const int mm = 500 + 5;
int n, m;
bool a[mm][mm];
bool test(int i, int j, int k, int l) {
    for (int x = i; x < k; i++) {
        if (a[x][j] != a[x][l]) return 0;
    }
    return 1;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < s.size(); j++) {
            a[i][j] = (s[j] == 'Y' ? 1 : 0);
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = i + 1; k < n; k++) {
                for (int l = j + 1; l < m; l++) {
                    if (test(i, j, k, l)) sum++;
                }
            }
        }
    }
    cout << sum << '\n';
}