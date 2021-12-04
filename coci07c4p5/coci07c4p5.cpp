#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int mm = 100000 + 5;
int N, dp[mm], K;
vector<pii> intervals;
int main() {
    cin >> N;
    for (int i = 1, A, B; i <= N; i++) {
        cin >> A >> B; intervals.push_back({A, B});
    }
    sort(intervals.begin(), intervals.end());
    
}