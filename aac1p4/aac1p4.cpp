#include <bits/stdc++.h>
using namespace std;
const int mm = 1e6 + 5, mq = 5e4 + 4;
struct query{int l, r, x, id;} q[mq];
int N, Q, a[mm], vis[mm], ans[mq];
bool cmp(query &a, query & b) { return a.r < b.r; }
int main() {
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> a[i]; 
    }
    for (int i = 1; i <= Q; i++) {
        cin >> q[i].l >> q[i].r >> q[i].x;
        q[i].id = i;
    }
    sort(q + 1, q + Q + 1, cmp);
    for (int i = 1, j = 1; i <= Q; i++) {
        while (j <= N && j <= q[i].r) {
            vis[a[j]] = j; j++;
        }
        for (int k = 1; k * k < q[i].x; k++) {
            if (q[i].x % k == 0) {
                if (vis[k] >= q[i].l && vis[q[i].x / k] >= q[i].l) {
                    ans[q[i].id] = 1; break;
                }
            }
        }
    }
    for (int i = 1; i <= Q; i++) cout << (ans[i] ? "YES\n" : "NO\n");
}