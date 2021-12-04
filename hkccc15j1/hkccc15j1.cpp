#include <bits/stdc++.h>
using namespace std;
const int mm = 100 + 5;
int N, a = 0, b = 0;
string s[mm];
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < N; i++) {
        string st; cin >> st;
        if (s[i] == "rock") {
            if (st == "paper") {
                b++;
            } else if (st == "scissors") {
                a++;
            }
        } else if (s[i] == "paper") {
            if (st == "rock") {
                a++;
            } else if (st == "scissors") {
                b++;
            }
        } else {
            if (st == "paper") {
                a++;
            } else if (st == "rock") {
                b++;
            }
        }
    }
    cout << a << ' ' << b;
}