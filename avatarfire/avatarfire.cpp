#include <bits/stdc++.h>
using namespace std;
const int mm = 1e4 + 5;
int N, K, s[mm];
int main() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> s[i];
    }
    sort(s + 1, s + 1 + N);
    for (int i = 1; i <= K; i++) {
        s[i] *= 2;
    }
    sort(s + 1, s + 1 + N);
    cout << s[1];
}