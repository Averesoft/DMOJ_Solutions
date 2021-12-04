#include <bits/stdc++.h>
using namespace std;
const int mm = 5 * 1e5 + 5;
int N, M, a[mm], b[mm], col = 0;
multiset<int> x, y;
unordered_map<int, int> um;
int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> a[i]; 
        if (a[i] != -1) x.insert(a[i] - i);
    }
    for (int i = 1; i <= M; i++) {
        cin >> b[i];
        if (b[i] != -1) y.insert(b[i] - i);
    }
    for (int u : x) {
        um[u]++;
    }
    for (int u : y) {
        if (um[u] > 0) {
            um[u]--; col++;
        }
    }
    cout << col << '\n';
}
