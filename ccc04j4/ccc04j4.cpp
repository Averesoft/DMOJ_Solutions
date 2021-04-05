#include <bits/stdc++.h>
using namespace std;
string a, b; 
vector<char> refer, words; 
int main() {
    getline(cin, a);
    getline(cin, b);
    for (int i = 0; i < b.size(); i++) {
        if (b[i] < 91 && b[i] > 64) {
            words.push_back(b[i]);
        }
    }
    for (int i = 0; i < a.size(); i++) {
        refer.push_back(a[i]);
    }
    for (int i = 0; i < words.size(); i++) {
        char x = words[i], y = refer[i % a.size()];
        x += (y - 65);
        if (x > 90) {
            x -= 26;
        }
        words[i] = x;
        cout << words[i];
    }
}