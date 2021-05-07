#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mm = 5 * 1e5 + 2021 + 10, inf = 0x3f3f3f3f;
ll n, a[mm], fib[4], dis[mm];
bool vis[mm];
vector<int> adj[mm];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dis, inf, sizeof (dis));
    cin >> n;
    fib[1] = 1; fib[2] = 1;
    a[1] = 2; a[2] = 3;
    for (ll i = 3; i <= n; i++) {
        fib[3] = fib[2] + fib[1];
        a[i] = (fib[3] % 2021) + (i % 50);
        fib[1] = fib[2]; fib[2] = fib[3];
    }
    for (int i = 1; i <= n; i++) {
        if (i + 1 < n) adj[i].push_back(i + 1); adj[i + 1].push_back(i);
        if (i - 1 >= 0) adj[i].push_back(i - 1); adj[i - 1].push_back(i);
        if (i + a[i] < n) adj[i].push_back(i + a[i]); adj[i + a[i]].push_back(i);
        if (i - a[i] >= 0) adj[i].push_back(i - a[i]); adj[i - a[i]].push_back(i);
    }
    queue<int> q; q.push(1); vis[1] = 1; dis[1] = 0;
    while(!q.empty()) {
        int node = q.front(); q.pop();
        for (int u : adj[node]) {
            if (!vis[u]) {
                vis[u] = 1;
                q.push(u);
                dis[u] = min(dis[u], dis[node] + 1);
            }
        }
    }
    cout << dis[n];
}

/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mm = 5 * 1e5 + 2021 + 10, inf = 0x3f3f3f3f;
ll n, a[mm], dp[mm], fib[4];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    memset(dp, inf, sizeof (dp)); 
    fib[1] = 1; fib[2] = 1;
    a[1] = 2; a[2] = 3;
    for (ll i = 3; i <= n; i++) {
        fib[3] = fib[2] + fib[1];
        a[i] = (fib[3] % 2021) + (i % 50);
        fib[1] = fib[2]; fib[2] = fib[3];
    }
    dp[1] = 0; dp[1 + a[1]] = dp[1] + 1;
    dp[2] = 1; dp[2 + a[2]] = dp[2] + 1;
    for (ll i = 3; i <= n; i++) {
        for (ll j = 1; j <= i; j++) {
            dp[i] = min(dp[j] + (i - j), dp[i]);
        }
        if (i + a[i] < mm) dp[i + a[i]] = min(dp[i + a[i]], dp[i] + 1);
        if (i - a[i] >= 0) dp[i - a[i]] = min(dp[i - a[i]], dp[i] + 1);
    }
    for (ll i = 1; i <= n; i++) {
        for (ll j = i + 1; j <= n; j++) {
            dp[i] = min(dp[i], dp[j] + (j - i));
        }
        if (i + a[i] < mm) dp[i + a[i]] = min(dp[i + a[i]], dp[i] + 1);
        if (i - a[i] >= 0) dp[i - a[i]] = min(dp[i - a[i]], dp[i] + 1);
    }
    cout << dp[n];
}
*/