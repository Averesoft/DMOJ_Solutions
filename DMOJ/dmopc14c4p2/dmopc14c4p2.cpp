#include <bits/stdc++.h>
using namespace std;
const int mm = 20 + 5;
int n, m, arr[mm];
vector<string> vc;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        vc.push_back(s);
    }
    cin >> m;
    for (int i = 0; i < vc.size(); i++) {
        int mi = INT_MAX, idx = -1;
        for (int j = 0; j < m; j++) {
            if (mi > arr[j]) {
                idx = j;
                mi = arr[j];
            }
        }
        arr[idx] += vc[i].size();
        cout << idx + 1 << '\n';
    }
}