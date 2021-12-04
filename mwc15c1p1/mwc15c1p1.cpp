#include <bits/stdc++.h>
using namespace std;
int N, X, Y;
vector<int> vc;
int main() {
    cin >> N;
    for (int i = 0, M, S; i < N; i++) {
        cin >> M >> S;
        vc.push_back(M * 60 + S);
    }
    sort(vc.begin(), vc.end());
    cin >> X >> Y;
    int sum = X * 60 + Y;
    for (int i = 0; i < N; i++) {
        sum -= vc[i];
        if (sum < 0) {
            cout << i; return 0;
        }
    }
    cout << N;
}