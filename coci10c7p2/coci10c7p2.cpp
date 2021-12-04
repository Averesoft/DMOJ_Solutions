#include <bits/stdc++.h>
using namespace std;
const int mm = 25 + 5;
int N, K;
char arr[mm];
bool alpha[26];
int main() {
    memset(alpha, 0, sizeof (alpha));
    memset(arr, '?', sizeof (arr));
    cin >> N >> K;
    int point = N;
    for (int i = 1; i <= K; i++) {
        int S; char ch; cin >> S >> ch; 
        while (S >= N) S -= N;
        point -= S; 
        if (point < 1) point += N;
        if (arr[point] != '?' && arr[point] != ch) {
            cout << '!'; return 0;
        } 
        arr[point] = ch; 
    }
    for (int i = 1; i <= N; i++) {
        if (arr[i] != '?' && alpha[arr[i] - 'A']) {
            cout << '!'; return 0;
        }
        alpha[arr[i] - 'A'] = 1;
    }
    for (int i = point; i <= N; i++) {
        cout << arr[i];
    }
    for (int i = 1; i < point; i++) {
        cout << arr[i];
    }
}