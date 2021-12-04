#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int mm = 1e6 + 5;
int N, H[mm], psa[mm];
vector<pii> vc;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0 ; i < N; i++) {
        cin >> H[i];
    }
    for (int i = 0; i < N; i++) {
        while (!vc.empty() && vc.back().first <= H[i]) {
            vc.pop_back();
        }
        if (vc.empty()) {
            cout << i << ' ';
        } else {
            cout << i - vc.back().second << ' ';
        }
        vc.push_back({H[i], i});
    }
}