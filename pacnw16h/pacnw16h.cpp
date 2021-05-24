#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const int mm = 2e5 + 5;
ll N, K, dp[mm]; pll p[mm];
bool cmp(ll val, pll x) { 
    return val <= x.first;
}
int main(){
    cin >> N >> K;
    for(int i = 1; i <= K; i++) {
        cin >> p[i].second >> p[i].first;
    }
    sort(p + 1, p + K + 1);
    for(int i = 1; i <= K; i++) {
        int lst = upper_bound(p + 1, p + i + 1, p[i].second, cmp) - p - 1;
        dp[i] = max(dp[i - 1], dp[lst] + p[i].first - p[i].second + 1);
    }
    cout << N - dp[K] << "\n";
}