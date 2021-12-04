#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N; 
int main() {
    cin >> N;
    ll name = 0;
    for (ll i = 1; i <= N; ) {
        string s; cin >> s;
        if (s[s.size() - 1] == ' ') {
            s = s.substr(0, s.size() - 1);
        }
        bool temp = 1;
        if (s[0] >= 'A' && s[0] <= 'Z') {
            if (s.size() == 1) {    
                temp = 1;
            } else {
                for (ll j = 1; j < s.length() - 1; j++) {
                    if ((s[j] >= '0' && s[j] <= '9') || (s[j] >= 'A' && s[j] <= 'Z')) {
                        temp = 0; break;
                    }
                }
                if (!(s[s.length() - 1] == '.' || s[s.length() - 1] == '?' || s[s.length() - 1] == '!' || (s[s.length() - 1] >= 'a' && s[s.length() - 1] <= 'z'))) {
                    temp = 0;
                }
            }
        } else {
            temp = 0;
        }
        if (temp) name++;
        if (s[s.length() - 1] == '.' || s[s.length() - 1] == '?' || s[s.length() - 1] == '!') {
            cout << name << '\n'; name = 0;
            i++;
        }
    }
}