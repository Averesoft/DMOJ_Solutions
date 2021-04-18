#include <bits/stdc++.h>
using namespace std;
int n;
set<int> st;
int main() {
    cin >> n;
    for (int i = 1, d; i <= n; i++) {
        cin >> d; st.insert(d);
    }
    cout << st.size();
}