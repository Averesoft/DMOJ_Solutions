#include <bits/stdc++.h>
using namespace std;
set<int> st;
int main() {
    for (int i = 0, a; i < 10; i++) {
        cin >> a;
        st.insert(a % 42);
    }
    cout << st.size();
}