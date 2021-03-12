#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int mm = 100000 + 5, INF = 0x3f3f3f3f;
int n, m, j, t = 0, dry[mm];
set<pii> st;
int main() {
    memset(dry, INF, sizeof dry);
    cin >> n >> m >> j;
    for (int i = 0, p, t; i < m; i++) {
        cin >> p >> t; dry[p] = t;
    }
    st.insert({INF, 0});
    dry[n + 1] = 0;
    int l = 0, r = 1;
    while (l <= n) {
        while(r <= n + 1) {
            if (r - l > j) {
                break;
            }
            st.insert({dry[r], r});
            r++;
        }
        pii temp = *st.begin();
        if (temp.first == INF) {
            t = -1;
            break;
        } 
        if (temp.second == n + 1) {
            break;
        }
        t = max(t, temp.first);
        while (l <= temp.second) {
            st.erase({dry[l], l});
            l++;
        }
        l--;
    }
    cout << t;
}