#include <bits/stdc++.h>
using namespace std;
int main() {
    string a, b; cin >> a >> b;
    int ha = stoi(a.substr(0, 2)) * 3600, hb = stoi(b.substr(0, 2)) * 3600;
    int ma = stoi(a.substr(3, 5)) * 60, mb = stoi(b.substr(3, 5)) * 60;
    int sa = stoi(a.substr(6)), sb = stoi(b.substr(6));
    cout << (hb + mb + sb) - (ha + ma + sa);
}