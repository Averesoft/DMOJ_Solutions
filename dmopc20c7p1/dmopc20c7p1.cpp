#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mm = 1e6 + 5;
int n, m[mm]; 
bool vis[mm];
vector<pii> vc;
queue<int> one, two;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int a = 0, b = 0;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> m[i]; 
        if (m[i] == 1) {
            a++; one.push(i);
        } else {
            b++; two.push(i);
        }
    }
    int M = 2 * n - max(a, b);
    cout << M << '\n';
    for (int i = 1; i <= M; i++) {
        cout << one.front() << ' ' << two.front() << '\n';
        one.pop(); two.pop();
    }
    if (one.empty()) {
        while (!two.empty()) {
            cout << two.front() << ' '; two.pop();
            cout << two.front() << '\n'; two.pop();
        }
    } else {
        while (!one.empty()) {
            cout << one.front() << ' '; one.pop();
            cout << one.front() << '\n'; one.pop();
        }
    }
}