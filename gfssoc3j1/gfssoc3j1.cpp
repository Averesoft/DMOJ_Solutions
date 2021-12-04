#include <bits/stdc++.h>
using namespace std;
int main() {
    string a, b; 
    getline(cin, a);
    getline(cin, b);
    if (a == "red" || a == "green" || a == "white") {
        if (b == "red" || b == "green" || b == "white") {
            cout << "Jingle Bells"; return 0;
        }
    }
    cout << "Boring...";
}