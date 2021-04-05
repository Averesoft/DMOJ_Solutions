#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> um;
vector<string> vc;
int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        vc.clear();
        string s; getline(cin, s);
        int idx = s.find(' '), pre = 0;
        while (idx != string::npos) {
            vc.push_back(s.substr(pre, idx));
            pre = idx;
            idx = s.find(' ');
        }
        for (string u : vc) {
            cout << u << ' ';
        }
    }
}