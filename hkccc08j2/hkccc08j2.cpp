#include <bits/stdc++.h>
using namespace std;
int N;
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        int sum = 0;
        while(1) {
            sum = 0;
            for (int j = 0; j < s.size(); j++) {
                sum += s[j] - '0';
            } 
            if (sum < 10) {
                break;
            } 
            s = to_string(sum);
        }
        cout << sum << '\n';
    }
}