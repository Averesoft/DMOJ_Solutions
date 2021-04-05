#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
pii solve(char ch) {
    if (ch == ' ') 
        return {4, 2};
    if (ch == '-') 
        return {4, 3};
    if (ch == '.') 
        return {4, 4};
    if (ch == '!') 
        return {4, 5};    
    if (ch <= 'F') 
        return {0, ch - 'A'};
    if (ch <= 'L') 
        return {1, ch - 'G'};
    if (ch <= 'R') 
        return {2, ch - 'M'};
    if (ch <= 'X') 
        return {3, ch - 'S'};
    if (ch <= 'Z') 
        return {4, ch - 'Y'};
}
int main() {
    string s; getline(cin, s);
    s = 'A' + s + '!';
    int sum = 0;
    for (int i = 1; i < s.size(); i++) {
        pii a = solve(s[i - 1]), b = solve(s[i]);
        sum += abs(a.first - b.first) + abs(a.second - b.second);
    }
    cout << sum;
}