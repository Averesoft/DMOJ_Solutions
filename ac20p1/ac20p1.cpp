#include <bits/stdc++.h>
using namespace std;
int main() {
    int T; cin >> T;
    while(T--) {
        int l1, l2, l3; cin >> l1 >> l2 >> l3;
        vector<int> vc; vc.push_back(l1); vc.push_back(l2); vc.push_back(l3);
        sort(vc.begin(), vc.end());
        if (vc[0] * vc[0] + vc[1] * vc[1] == vc[2] * vc[2]) {
            cout << "R\n";
        } else if (vc[0] * vc[0] + vc[1] * vc[1] > vc[2] * vc[2]) {
            cout << "A\n";
        } else {
            cout << "O\n";
        }
    }
}