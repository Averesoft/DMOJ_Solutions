#include <bits/stdc++.h>
using namespace std;
int main() {
    string a, b; cin >> a >> b;
    string adj;
    if (b[b.size() - 1] == 'e') {
        adj = "la";
    } else if (b[b.size() - 1] == 's') {
        adj = "les";
    } else {
        adj = "le";
    }
    printf("%s-tu %s %s ? ", a.c_str(), adj.c_str(), b.c_str());
}