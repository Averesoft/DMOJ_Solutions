#include <bits/stdc++.h>
using namespace std;
int main() {
    int nott = 0;
    string s;
    while(1) {
        cin >> s;
        if (s == "not") {
            nott++;
        } else {
            break;
        }
    }
    cin >> s;
    if (s == "True") {
        if (nott % 2 == 0) {
            cout << "True";
        } else {
            cout << "False";
        }
    } else {
        if (nott % 2 == 0) {
            cout << "False";
        } else {
            cout << "True";
        }
    }
}