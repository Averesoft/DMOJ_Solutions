#include <bits/stdc++.h>
using namespace std;
int n;
int angle(char x, char y) {
    int a1, a2;
    switch (x) {
        case 'E': a1 = 0;
            break;
        case 'N': a1 = 90;
            break;
        case 'W': a1 = 180;
            break;
        case 'S': a1 = 270;
            break;
    }
    switch (y) {
        case 'E': a2 = 0;
            break; 
        case 'N': a2 = 90;
            break;
        case 'W': a2 = 180;
            break;
        case 'S': a2 = 270;
            break;
    }
    if (a1 == a2) {
        return 0;
    } else if ((a1 + 90) % 360 == a2) {
        return 90;
    } else if ((a1 + 270) % 360 == a2) {
        return -90;
    }
}
int main() {
    cin >> n;
    while (n--) {
        string s; cin >> s;
        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            sum += angle(s[i], s[(i + 1) % s.size()]);
        }
        if (sum == 360) {
            cout << "C";
        }
        cout << "CW\n";
    }
}