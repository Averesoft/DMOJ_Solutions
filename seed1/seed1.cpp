#include <bits/stdc++.h>
using namespace std;
bool a[5];
int main() {
    memset(a, 0, sizeof a);
    string s; cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'B') a[0] = 1;
        else if (s[i] == 'F') a[1] = 1;
        else if (s[i] == 'T') a[2] = 1;
        else if (s[i] == 'L') a[3] = 1;
        else if (s[i] == 'C') a[4] = 1;
    }
    if (!a[0]) cout << 'B';
    if (!a[1]) cout << 'F';
    if (!a[2]) cout << 'T';
    if (!a[3]) cout << 'L';
    if (!a[4]) cout << 'C';
    for (int i = 0; i < 5; i++) {
        if (!a[i]) return 0;
    }
    cout << "NO MISSING PARTS";
}