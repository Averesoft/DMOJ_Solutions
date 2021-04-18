#include <bits/stdc++.h>
using namespace std;
int n;
string s[8];
string years[] = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
map<string, int> mp;
string animal(int x) {
    int a = 0, b = 2021;
    while(b < x) {
        a++; b++; 
        if (a >= 12) {
            a = 0;
        }
    }
    while(b > x) {
        a--; b--;
        if (a <= -1) {
            a = 11;
        }
    }
    return years[a];
}
int main() {
    cin >> n;
    mp["Bessie"] = 2021;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> s[j];
        }
        mp[s[0]] = mp[s[7]];
        do {
            if (s[3] == "previous") {
                mp[s[0]]--;
            } else {
                mp[s[0]]++;
            }
        } while(animal(mp[s[0]]) != s[4]);
    }
    int ans = abs(mp["Bessie"] - mp["Elsie"]);
    cout << ans;
}