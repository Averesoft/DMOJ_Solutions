#include <bits/stdc++.h>
using namespace std;
const int mm = 5000 + 5;
int n, m, s, ans, l[500000 + 5], r[500000 + 5];
vector<string> a; 
bool f[35][35];
int main() {
    cin >> n >> m >> s; a.resize(n + 5);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> l[i] >> r[i]; l[i]--; r[i]--;
    }
    for (int i = 0; i < n; i++) {
        memset(f, false, sizeof f);
        for (int p = 0; p < s; p++) {
            for (int q = p; q < s; q++) {
                f[p][q] = true;
                for (int pl = p, pr = q; pl < pr; pl++, pr--) {
                    if (a[i][pl] != a[i][pr]) {
                        f[p][q] = false;
                        break;
                    } 
                }
            }
        }
        bool flag = true;
        for (int j = 0; j < m && flag; j++) {
            if (!f[l[j]][r[j]]) {
                flag = false;
            }
        }
        if (flag) ans++;
    }
    cout << ans;
}