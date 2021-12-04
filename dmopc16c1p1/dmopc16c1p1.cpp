#include <bits/stdc++.h>
using namespace std;
const int mm = 30 + 5;
int N, A[mm], cnt = 0;
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i]; 
        if (A[i] % 2 == i % 2) {
            cnt++;
        }
    }
    cout << cnt;
}