#include <bits/stdc++.h>
using namespace std;
const int mm = 1e6 + 5;
int N, Q, a[mm], parent[mm], size[mm], val[mm];
int main() {
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= Q; i++) {
        int query; cin >> query;
        if (query == 1) {
            int a, b; cin >> a >> b;
        } else if (query == 2) {
            int a; cin >> a;
        } else if (query == 3) {
            int a; cin >> a;
        }
    }
}