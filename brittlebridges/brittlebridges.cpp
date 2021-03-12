#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int mm = 200000 + 5;
int n, v[mm];
vector<int> edg[mm];
void dijk() {
    
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, t; cin >> a >> b >> t;
        edg[a].push_back(b); edg[b].push_back(a);
    }
    dijk(); 
}