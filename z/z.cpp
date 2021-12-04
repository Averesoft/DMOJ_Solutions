#include <bits/stdc++.h>
using namespace std;
int N = 1000, forw = 0, depth = 0, aim = 0;
int main() {
    for (int i = 1; i<= N; i++) {
        string s; int num; cin >> s >> num;
        if (s == "forward") {
            forw += num; depth += aim * num;
        } else if (s == "down") {
            aim += num;
        } else if (s == "up") {
            aim -= num;
        }
    }
    cout << forw * depth;
}