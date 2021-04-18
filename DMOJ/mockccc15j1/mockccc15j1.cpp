#include <bits/stdc++.h>
using namespace std;
int main() {
    string area, s; cin >> area >> s;
    if ((area == "416" || area == "647" || area == "437") && s.size() == 7) {
        if (area == "416") {
            cout << "valuable";
        } else {
            cout << "valueless";
        }
    } else {
        cout << "invalid";
    }
}