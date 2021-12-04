#include <bits/stdc++.h>
using namespace std;
int a[3];
string s;
int main() {
    cin >> a[0] >> a[1] >> a[2];
    cin >> s;
    sort(a, a + 3);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') {
            cout << a[0];
        } else if (s[i] == 'B') {
            cout << a[1];
        } else if (s[i] == 'C') {
            cout << a[2];
        }
        cout << ' ';
    }
}