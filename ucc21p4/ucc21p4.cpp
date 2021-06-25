#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mm = 5 * 1e6 + 5, inf = 0x3f3f3f3f;
ll n, a[mm], fib[mm], vis[mm];
vector<int> adj[mm];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    fib[1] = 1; fib[2] = 1; a[1] = 2; a[2] = 3;
    for (ll i = 3; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2]; fib[i] %= 2021;
        a[i] = fib[i] + i % 50;
    }
    queue<int> q; q.push(1);
    while(!q.empty()) {
        int node = q.front(); q.pop();
        if (node == n) {
            cout << vis[n]; break;
        }
        if (node + 1 <= n && !vis[node + 1]) {
            vis[node + 1] = vis[node] + 1; q.push(node + 1);
        } 
        if (node - 1 >= 1 && !vis[node - 1]) {
            vis[node - 1] = vis[node] + 1; q.push(node - 1);
        } 
        if (node + a[node] <= n && !vis[node + a[node]]) {
            vis[node + a[node]] = vis[node] + 1; q.push(node + a[node]);
        }
        if (node - a[node] >= 1 && !vis[node - a[node]]) {
            vis[node - a[node]] = vis[node] + 1; q.push(node - a[node]);
        }
    }
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