#include <bits/stdc++.h>
using namespace std;
int r, l;
set<int> st;
vector<int> vc;
int main() {
    cin >> r >> l;
    for (int i = 0; i < r; i++) {
        int line = 0;
        for (int j = 0, light; j < l; j++) {
            cin >> light; 
            line = ((line << 1) | light);
        }
        vc.push_back(line);
    }
    int bits = 0;
    for (int i = r - 1; i >= 0; i--) {
        bits = bits ^ vc[i];
        st.insert(bits);
    }
    cout << st.size();
}