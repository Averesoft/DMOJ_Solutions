#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int mm = 1e5 + 5;
set<pii> arr[mm];
int N, S, d[mm], s[mm], a[mm], Q;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> S;
    for (int i = 1; i <= N; i++) {
        cin >> d[i]; 
    }
    for (int i = 1; i <= S; i++) {
        cin >> s[i] >> a[i];
        arr[a[i]].insert({d[s[i]], s[i]});
    }
    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        char op; cin >> op;
        if (op == 'A') {
            int x, k; cin >> x >> k;s
            arr[k].insert({d[x], x});
        } else if (op == 'S') {
            int x, k; cin >> x >> k;
            arr[k].erase({d[x], x});
        } else if (op == 'E') {
            int x, k; cin >> x >> k;
            for (int j = 1; j <= 100 + 5; j++) {
                if (arr[j].find({d[x], x}) != arr[j].end()) {
                    arr[j].erase({d[x], x});
                }
            }
            d[x] = k;
        } else if (op == 'Q') {
            int k; cin >> k;
            cout << (arr[k].empty() ? -1 : arr[k].begin() -> second) << '\n';
        }
    }
}