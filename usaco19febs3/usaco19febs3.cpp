#include <bits/stdc++.h>
using namespace std;
const int mm = 1e5 + 5;
int n, m;
int vis[mm];
vector<int> sadj[mm], dadj[mm];
bool maybe = false;
void dfs(int a, int b)
{
    vis[a] = b;
    for (int n : sadj[a]) {
        if (vis[n] == 3 - b) {
            maybe = true; 
        }
        if (vis[n] == 0) {
            dfs(n, b);
        }
    }
    for (int n : dadj[a]) {
        if (vis[n] == b) {
            maybe = true; 
        }
        if (vis[n] == 0) {
            dfs(n, 3 - b);
        }
    }  
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        char ch; cin >> ch;
        int a, b; cin >> a >> b;
        if (ch == 'S') {
            sadj[a].push_back(b);
            sadj[b].push_back(a);
        } else if (ch == 'D') {
            dadj[a].push_back(b);
            dadj[b].push_back(a);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, 1);
            ans++;
        }
    }
    if (maybe) {
        cout << '0';
        return 0;
    }
    cout << '1';
    for (int i = 0; i < ans; i++) {
        cout << '0';
    }
}