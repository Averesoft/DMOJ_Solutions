#include <bits/stdc++.h>
using namespace std;
const int mm = 5000 + 5, buf = 100000;
int N, A[mm], ans = 0;
unordered_map<int, int> vis;
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        for (int j = 1; j < i; j++) {  
            if (vis[A[i] - A[j] + buf]) {
                ans++; break;
            }
        }
        for (int j = 1; j <= i; j++) {
            vis[A[i] + A[j] + buf] = 1;
        }   
    }
    cout << ans;
}