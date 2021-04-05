#include <bits/stdc++.h>
using namespace std;
set<int> st;
int main() {
    int n; cin >> n;    
    for (int i = 0, a; i < n; i++) {
        cin >> a; st.insert(a);
    }
    cout << st.size();
}