//M S T is the BE S T 
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int mm = 1e5 + 5;
int n, m, f[mm], pre[mm], siz[mm], sum = 0;
priority_queue<pii, vector<pii>, greater<pii>> pq;
int root(int node) {
    return node == pre[node] ? node : pre[node] = root(pre[node]);
}
bool solve(int a, int b) {
    int x = root(a), y = root(b);
    if (x == y) {
        return 0;
    }
    if (siz[x] < siz[y]) {
        swap(x, y);
    }
    pre[y] = pre[a] = pre[b] = x;
    siz[x] += siz[y];
    return 1;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
        pre[i] = i;
        siz[i] = 1;
    }
    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y; 
        solve(x, y);
    }
    for (int i = 1; i < n; i++) {
        pq.emplace(f[i + 1] - f[i], i);
    }
    while (pq.size() != 0) {
        pii node = pq.top(); pq.pop();
        if (solve(node.second, node.second + 1)) {
            sum += node.first;
        }
    }
    cout << sum << '\n';
}
