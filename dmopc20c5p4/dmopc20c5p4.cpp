#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int base = 131;
int N, M; vector<string> a, s; ll ans; unordered_map<ll, int> mp;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M; s.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }
    if (N > M) {
        a.resize(M, string(N, ' '));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                a[i][j] = s[j][i];
            }
        }
        swap(N, M); swap(a, s);
    }
    for (int r1 = 0; r1 < N; r1++) {
        vector<ll> hsh(M, 0); 
        for (int r2 = r1 + 1; r2 < N; r2++) {
            for (int c = 0; c < M; c++) {
                hsh[c] = hsh[c] * base + s[r2][c];
            }
            mp.clear();
            for (int c = 0; c < M; c++) {
                if(s[r1][c] == s[r2][c]) {
                    ans += mp[hsh[c]]; mp[hsh[c]]++;
                } else {
                    mp.clear();
                }
            }
        }
    }
    cout << ans << '\n';    
}
