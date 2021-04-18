#include <bits/stdc++.h>
using namespace std;
vector<string> adj, nouns;
int main() {
    int n, m; cin >> n >> m;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s; adj.push_back(s);
    }
    for (int i = 0; i < m; i++) {
        cin >> s; nouns.push_back(s);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%s as %s\n", adj[i].c_str(), nouns[j].c_str());
        }
    }
}