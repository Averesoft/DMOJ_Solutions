#include <bits/stdc++.h>
using namespace std;
const int mm = 1e5 + 5;
int N;
bool vis[mm];
int main() {
    cin >> N;
    for (int i = 0, a; i < N - 1; i++) {
        cin >> a;
        vis[a] = 1;
    }
    for (int i = 1 ; i <= N; i++) {
        if (!vis[i]) {
            cout << i; return 0;
        }
    }
}