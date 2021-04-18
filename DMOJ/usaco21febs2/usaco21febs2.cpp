#include <bits/stdc++.h>
using namespace std;
const int mm = 65536 + 5;
int n, k;
int ancestors[mm];
set<int> sec;
vector<int> vc;
int main() {
    cin >> n >> k;
    for (int i = 0;i < n; i++) {
        cin >> ancestors[i];
        sec.insert((ancestors[i]+11)/12);
    }
    int ans = *sec.rbegin(), pre = 0;
    while(!sec.empty()) {
        vc.push_back(*sec.begin() - 1 - pre);
        pre = *sec.begin();
        sec.erase(*sec.begin());
    }
    sort(vc.rbegin(), vc.rend());
    for (int i = 0; i < vc.size() && i < k - 1; i++) {
        ans -= vc[i];
    }
    cout << ans * 12;
}