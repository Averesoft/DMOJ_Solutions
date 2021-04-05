//mfw bruce puts catgirls on the hw
#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
const int mm = 2 * 1e5 + 5, inf = 0x3f3f3f3f;
int dp[mm]; 
unordered_set<string> s;
int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string st; cin >> st; s.insert(st);
    }
    for (int i = 0; i < 10; i++) {
        string t; cin >> t;
        fill(dp, dp + t.size() + 1, inf);
        dp[0] = -1;
        for (int j = 0; j < t.size(); j++) {
            for (int k = 0; j + k <= t.size(); k++) {
                if (s.find(t.substr(j, k)) != s.end()) {
                    dp[j + k] = min(dp[j + k], dp[j] + 1);
                }
            }
        }
        cout << dp[t.size()] << '\n';
    }
}