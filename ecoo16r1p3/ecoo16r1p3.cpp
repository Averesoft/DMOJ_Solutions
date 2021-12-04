#include <bits/stdc++.h>
using namespace std;
const int mm = 1000 + 5;
int N; bool ina[mm], inb[mm]; stack<int> a, b;
void solve() {
    while(!a.empty()) a.pop();
    while(!b.empty()) b.pop();
    memset(ina, 0, sizeof (ina));
    memset(inb, 0, sizeof (inb));
    cin >> N; 
    for (int i = 0, x; i < N; i++) {
        cin >> x; a.push(x); ina[x] = 1;
    }
    int cnt = 0;
    for (int i = N; i >= 1; i--) {
        if (ina[i]) {
            int tmp = 0;
            while(tmp != i) {
                tmp = a.top(); a.pop(); ina[tmp] = 0; inb[tmp] = 1; 
                b.push(tmp); 
                cnt++;
            }
            b.pop();
        } else {
            int tmp = 0;
            while(tmp != i) {
                tmp = b.top(); b.pop(); inb[tmp] = 0; ina[tmp] = 1; 
                a.push(tmp); 
                cnt++;
            }
            a.pop();
        }
    }
    cout << cnt << '\n';
}
int main() {
    int T = 10;
    while(T--) {
        solve();
    }
}