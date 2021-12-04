#include <bits/stdc++.h>
using namespace std;
const int mm = 1024 + 5;
int lo = 0, up = 0;
char ch[mm];
int main() {
    string s; getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        ch[i] = s[i];
        if (s[i] != ' ' && s[i] < '0' && s[i] > '9') {
            if (s[i] >= 'a' && s[i] <= 'z') {
                lo++;
            } else if (s[i] >= 'A' && s[i] <= 'Z') {
                up++;
            }
        }
    }
    if (up != lo) {
        if (up > lo) {
            for (int i = 0; i < s.size(); i++) {
                if (s[i] >= 'a' && s[i] <= 'z') {
                    ch[i] -= 'a' - 'A';
                } 
            }
        } else if (lo > up) {
            for (int i = 0; i < s.size(); i++) {
                if (s[i] >= 'A' && s[i] <= 'Z') {
                    ch[i] += 'a' - 'A';
                }
            }
        }
    } 
    for (int i = 0; i < s.size(); i++) {
        cout << ch[i];
    }
}