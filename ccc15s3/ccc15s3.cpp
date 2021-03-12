#include <bits/stdc++.h>
using namespace std;
const int mm = 1e5 + 5;
int G, P;
set<int> s;
int main() {
    cin >> G;
    cin >> P;
    for (int i = 1; i <= G; i++) {
        s.insert(i);
    }
    int ans = 0;
    for (int i = 1, g; i <= P; i++) {
        cin >> g;
        if (s.upper_bound(g) == s.begin()) {
            break;
        }
        s.erase(--s.upper_bound(g));
        ans++;
    }
    cout << ans;
}