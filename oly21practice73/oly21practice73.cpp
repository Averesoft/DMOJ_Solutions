#include <bits/stdc++.h>
using namespace std;
const int mm = 1e5 + 5;  
int N, a[mm];  
deque<int> vc;
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + N);
    for (int i = 1; i <= N / 2; i++) {
        vc.push_back(a[i]); vc.push_back(a[N - i + 1]);
    }
    if (N % 2) {
        vc.push_front(a[N / 2 + 1]);
    }
    int sum = 0;
    for (int i = 0; i < N - 1; i++) {
        sum += abs(vc[i] - vc[i + 1]);
    }
    cout << sum;
}