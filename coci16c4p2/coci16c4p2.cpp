#include <bits/stdc++.h>
using namespace std;
int N;
char A[4][8] = {
    {'*', '*', '*', 'A', 'B', 'C', 'D', 'E'},
    {'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M'},
    {'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U'},
    {'V', 'W', 'X', 'Y', 'Z', '*', '*', '*'}
};
bool arr[26];
vector<string> vc;
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        string s; cin >> s;
        vc.push_back(s);
    }
    string x; cin >> x;
    for (string s : vc) {
        if (s.substr(0, x.size()) == x) {
            arr[s[x.size()] - 'A'] = 1;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (!arr[i]) {
            A[(i + 3) / 8][(i + 3) % 8] = '*';
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            cout << A[i][j];
        }
        cout << '\n';
    }
}
