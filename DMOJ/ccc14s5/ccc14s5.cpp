#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> pii;
const int mm = 2002;
int n, x[mm], y[mm], mx[mm], dp[mm], tmp[mm];
vector<pii> vec;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        for (int j = 0; j < i; j++) {
            int d = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            vec.push_back({ d, {j, i } });
        }
    }
    sort(vec.begin(), vec.end());
    for (pii e : vec) {
        int d = e.first, u = e.second.first, v = e.second.second;
        if (d > mx[u]) {
            mx[u] = d; tmp[u] = dp[u];
        }
        if (d > mx[v]) {
            mx[v] = d; tmp[v] = dp[v];
        }
        dp[u] = max(dp[u], tmp[v] + 1);
        if (u != 0) {
            dp[v] = max(dp[v], tmp[u] + 1);
        }
        else {

        }
    }
    cout << dp[0];
}