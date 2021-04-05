#include <bits/stdc++.h>
using namespace std;
vector<char> suits[4];
string suitnames[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
string s; 
int main() {
    cin >> s;
    int suit;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'C') {
            suit = 0;
        } else if (s[i] == 'D') {
            suit = 1;
        } else if (s[i] == 'H') {
            suit = 2;
        } else if (s[i] == 'S') {
            suit = 3;
        } else {
            suits[suit].push_back(s[i]);
        }
    }
    printf("Cards Dealt\t Points\n");
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        int points = 0;
        printf("%s ", suitnames[i].c_str());
        for (int j = 0; j < suits[i].size(); j++) {
            printf("%c ", suits[i][j]);
            if (suits[i][j] == 'J') {
                points++;
            } else if (suits[i][j] == 'Q') {
                points += 2;
            } else if (suits[i][j] == 'K') {
                points += 3;
            } else if (suits[i][j] == 'A') {
                points += 4;
            }
        }
        if (suits[i].size() < 3) {
            points += 3 - suits[i].size();
        }
        sum += points;
        printf("\t%d\n", points);
    }
    printf("Total %d", sum);
}