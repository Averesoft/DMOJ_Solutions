#include <bits/stdc++.h>
using namespace std;
int N, P;
stack<int> st[7];
int main() {
    cin >> N >> P;
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        int s, f; cin >> s >> f;
        while(!st[s].empty() && st[s].top() > f) {
            st[s].pop(); cnt++;
        }
        if (!st[s].empty()) {
            if (st[s].top() != f) {
                st[s].push(f); cnt++;
            }
        } else {
            st[s].push(f); cnt++;
        }
    }
    cout << cnt;
}