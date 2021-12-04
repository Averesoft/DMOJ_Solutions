#include <bits/stdc++.h>
using namespace std;
int N;
vector<string> adj[26];
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        adj[s[0] - 'a'].push_back(s);
    }
    for (int i = 0; i < 26; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    for (int i = 0; i < 26; i++) {
        if (adj[i].size() > 0) {
            for (int j = 0; j < adj[i].size(); j++) {
                cout << adj[i][j];
                if (j != adj[i].size() - 1) {
                    cout << ", ";
                }
            }
            cout << '\n';
        }
    }
}