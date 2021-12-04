#include <bits/stdc++.h>
using namespace std;
string a, b;
int fre[27];
int main() {
    cin >> a >> b;
    int ast = 0, cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        fre[a[i] - 'a']++;
    }
    for (int i = 0; i < b.size(); i++) {
        if (b[i] == '*') {
            ast++;
        } else if (fre[b[i] - 'a'] > 0) {
            cnt++; fre[b[i] - 'a']--; 
        }
    }
    cout << (cnt + ast == a.size() ? "A" : "N");
}