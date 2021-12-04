#include <bits/stdc++.h>
using namespace std;
int N; string s;
int main() {
    cin >> N;
    cin >> s;
    int size = 1;
    string pal = s.substr(0, 1);
    for (int i = 1; i < N - 1; i++) {
        int buf = 1;
        while(1) {
            if (i - buf >= 0 && i + buf < N) {
                if (s[i - buf] == s[i + buf]) {
                    buf++;
                } else {
                    break;
                }
            } else {
                break;
            }
        }
        if (2 * buf + 1 > size && i - buf >= 0 && i + buf + 1 <= N) {
            size = 2 * buf + 1;
            pal = s.substr(i - buf, i + buf + 1);        
        }
    }
    cout << pal << '\n' << size;
}