#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef pair<int, int> pii;
const int mm = 300 + 5;
int N, Q, P[mm];
unordered_map<int, int> um, um1;
void swap(int x, int y) {
    int i = um1[x], j = um1[y];
    um[i] += um[j]; um[j] = um[i] - um[j]; um[i] -= um[j];
    um1[x] = j; um1[y] = i;
}
void swap1(int x, int y) {
    um[x] += um[y]; um[y] = um[x] - um[y]; um[x] -= um[y];
    um1[um[x]] = x;
    um1[um[y]] = y;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        um[i] = um1[i] = i;
    }
    for (int i = 1; i <= Q; i++) {
        char ch; cin >> ch;
        if (ch == 'B') {
            int x, y; cin >> x >> y;
            swap(x, y);
        } else if (ch == 'E') {
            int x, y; cin >> x >> y;
            swap1(x, y);
        } else if (ch == 'Q') {
            for (int j = 1, a; j <= N; j++) {
                cin >> a; P[um[j]] = a;
            }
            for (int j = 1; j <= N; j++) {
                cout << P[j] << (j < N ? ' ':'\n');
            }
        }
    }
}