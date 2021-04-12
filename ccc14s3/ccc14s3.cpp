#include <bits/stdc++.h>
using namespace std;
const int mm = 100000 + 5;
stack<int> a, b, c;
int loc[mm];
void solve() {
    memset(loc, 0, sizeof loc);
    while(!a.empty()) a.pop();
    while(!b.empty()) b.pop();
    while(!c.empty()) c.pop();
    int n; cin >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> x; a.push(x);
        loc[x] = 1;
    }
    while(a.top() != 1) {
        b.push(a.top());
        loc[a.top()] = 2;
        a.pop();
    }
    for (int i = 2; i <= n; i++) {
        if (loc[i] == 1) {
            
        } else {

        }
    }
    
}
int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}