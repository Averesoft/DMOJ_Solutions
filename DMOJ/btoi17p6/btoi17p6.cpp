#include <bits/stdc++.h>
using namespace std;
const int mm = 2e5 + 5;
int n, d, dis[mm], ans;
vector<int> adj[mm];
void dfs(int u, int pre) {
    deque<int> deck;
    for (int v : adj[u]) {
        if (v == pre) continue;
        dfs(v, u); deck.push_back(dis[v] + 1);
    }
    sort(deck.begin(), deck.end());
    while(deck.size() >= 2 && deck[0] + deck[1] < d) {
        ans--; deck.pop_front();
    }
    if (deck.empty()) {
        dis[u] = 0;
    } else {
        dis[u] = deck[0] % d;
    }
    if (dis[u] == 0) {
        ans++;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> d;
    for (int i = 1, x; i < n; i++) {
        cin >> x; adj[x].push_back(i); adj[i].push_back(x);
    }
    dfs(0, -1);
    cout << ans;
}